#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import re
import json
import subprocess
import shutil
from typing import Dict, List, Optional, Tuple

class MSHFunctionFixer:
    def __init__(self, report_file: str = "msh_function_check_report.json"):
        self.report_file = report_file
        self.report_data = None
        self.fixed_files = set()
        self.header_declarations_to_remove = {}  # 记录需要从头文件中删除的函数声明

    def load_report(self) -> bool:
        """加载检查报告"""
        try:
            with open(self.report_file, 'r', encoding='utf-8') as f:
                self.report_data = json.load(f)
            print(f"成功加载报告，共 {self.report_data['total_functions']} 个函数")
            print(f"合规函数: {self.report_data['compliant_functions']}")
            print(f"不合规函数: {self.report_data['non_compliant_functions']}")
            return True
        except Exception as e:
            print(f"加载报告失败: {e}")
            return False

    def restore_files(self):
        """恢复所有修改过的文件"""
        print("正在恢复修改过的文件...")
        restored_count = 0
        
        for root, dirs, files in os.walk('.'):
            for file in files:
                if file.endswith('.c') or file.endswith('.h'):
                    file_path = os.path.join(root, file)
                    backup_path = file_path + '.bak'
                    
                    if os.path.exists(backup_path):
                        try:
                            shutil.copy2(backup_path, file_path)
                            restored_count += 1
                        except Exception as e:
                            print(f"恢复文件失败 {file_path}: {e}")
        
        print(f"已恢复 {restored_count} 个文件")

    def backup_file(self, file_path: str):
        """备份文件"""
        backup_path = file_path + '.bak'
        if not os.path.exists(backup_path):
            try:
                shutil.copy2(file_path, backup_path)
            except Exception as e:
                print(f"备份文件失败 {file_path}: {e}")

    def read_file_content(self, file_path: str) -> List[str]:
        """读取文件内容"""
        try:
            with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                return f.readlines()
        except Exception as e:
            print(f"读取文件失败 {file_path}: {e}")
            return []

    def write_file_content(self, file_path: str, lines: List[str]):
        """写入文件内容"""
        try:
            with open(file_path, 'w', encoding='utf-8') as f:
                f.writelines(lines)
            self.fixed_files.add(file_path)
        except Exception as e:
            print(f"写入文件失败 {file_path}: {e}")

    def find_function_body_range(self, lines: List[str], start_line: int) -> Tuple[int, int]:
        """找到函数体的范围"""
        if start_line >= len(lines):
            return start_line, start_line
            
        # 找到函数开始的 { 
        brace_count = 0
        in_function = False
        function_start = start_line
        
        for i in range(start_line, len(lines)):
            line = lines[i]
            
            if '{' in line:
                brace_count += line.count('{')
                in_function = True
                if brace_count == 1:
                    function_start = i
            elif '}' in line:
                brace_count -= line.count('}')
                if brace_count == 0 and in_function:
                    return function_start, i
        
        return function_start, len(lines) - 1

    def fix_function_signature_comprehensive(self, file_path: str, line_number: int, current_params: str, return_type: str) -> bool:
        """全面修复函数签名 - 处理所有可能的格式"""
        lines = self.read_file_content(file_path)
        if not lines:
            return False
        
        # 转换为0基索引
        line_idx = line_number - 1
        if line_idx >= len(lines):
            return False
        
        original_line = lines[line_idx]
        modified = False
        
        # 1. 修复参数格式 - 全面处理各种参数格式
        if current_params != "int argc, char **argv":
            new_line = original_line
            
            # 处理 char *argv[] 到 char **argv 的转换
            if re.search(r'char\s*\*\s*argv\s*\[\]', new_line):
                new_line = re.sub(r'char\s*\*\s*argv\s*\[\]', 'char **argv', new_line)
                modified = True
            # 处理 char** argv 到 char **argv 的转换
            elif re.search(r'char\*\*\s*argv', new_line):
                new_line = re.sub(r'char\*\*\s*argv', 'char **argv', new_line)
                modified = True
            # 处理 char**argv 到 char **argv 的转换
            elif re.search(r'char\*\*argv', new_line):
                new_line = re.sub(r'char\*\*argv', 'char **argv', new_line)
                modified = True
            # 处理 char* argv[] 到 char **argv 的转换
            elif re.search(r'char\*\s*argv\s*\[\]', new_line):
                new_line = re.sub(r'char\*\s*argv\s*\[\]', 'char **argv', new_line)
                modified = True
            # 处理 const char *argv[] 到 char **argv 的转换
            elif re.search(r'const\s+char\s*\*\s*argv\s*\[\]', new_line):
                new_line = re.sub(r'const\s+char\s*\*\s*argv\s*\[\]', 'char **argv', new_line)
                modified = True
            
            # 处理空参数或void参数
            if current_params == "void" or current_params == "":
                # 在函数名后添加标准参数
                new_line = re.sub(r'(\w+\s*\()\s*(void)?\s*(\))', r'\1int argc, char **argv\3', new_line)
                modified = True
            # 处理 char** argv 格式（注意空格）
            elif re.search(r'char\*\*\s*argv', new_line):
                new_line = re.sub(r'char\*\*\s*argv', 'char **argv', new_line)
                modified = True
            
            if new_line != original_line:
                lines[line_idx] = new_line
                modified = True
        
        # 2. 修复返回类型 - 处理所有可能的返回类型
        if return_type != "int":
            # 将非int返回类型改为int
            if 'static' in lines[line_idx]:
                lines[line_idx] = re.sub(r'\b(void|long|rt_err_t|size_t|rt_size_t|rt_uint32_t|rt_uint64_t|uint32_t|uint64_t)\b', 'int', lines[line_idx])
            else:
                lines[line_idx] = re.sub(r'\b(void|long|rt_err_t|size_t|rt_size_t|rt_uint32_t|rt_uint64_t|uint32_t|uint64_t)\b', 'static int', lines[line_idx])
            modified = True
        
        # 如果修改了行，写入文件
        if modified:
            self.write_file_content(file_path, lines)
            return True
        
        return False

    def add_return_statement(self, file_path: str, function_name: str, function_start_line: int) -> bool:
        """添加返回语句"""
        lines = self.read_file_content(file_path)
        if not lines:
            return False
        
        # 找到函数体
        start_idx, end_idx = self.find_function_body_range(lines, function_start_line - 1)
        
        # 检查是否已经有返回语句
        has_return = False
        for i in range(start_idx, end_idx + 1):
            line = lines[i]
            if re.search(r'\breturn\s+', line):
                has_return = True
                break
        
        if not has_return:
            # 在函数结束前添加返回语句
            for i in range(end_idx, start_idx - 1, -1):
                if '}' in lines[i] and i > start_idx:
                    # 在最后一个}前添加return语句
                    lines.insert(i, "    return 0;\n")
                    self.write_file_content(file_path, lines)
                    return True
        
        return False

    def add_rt_unused_macros(self, file_path: str, function_name: str, function_start_line: int) -> bool:
        """添加RT_UNUSED宏"""
        lines = self.read_file_content(file_path)
        if not lines:
            return False
        
        # 找到函数体
        start_idx, end_idx = self.find_function_body_range(lines, function_start_line - 1)
        
        # 检查是否已经有RT_UNUSED宏
        has_argc_unused = False
        has_argv_unused = False
        
        for i in range(start_idx, min(start_idx + 20, end_idx + 1)):
            line = lines[i]
            if 'RT_UNUSED(argc)' in line:
                has_argc_unused = True
            if 'RT_UNUSED(argv)' in line:
                has_argv_unused = True
        
        modified = False
        
        # 找到函数体开始的位置（第一个{后面）
        body_start = -1
        for i in range(start_idx, end_idx + 1):
            if '{' in lines[i]:
                body_start = i + 1
                # 跳过空行和注释
                while body_start <= end_idx and (lines[body_start].strip() == '' or 
                                                lines[body_start].strip().startswith('/*') or
                                                lines[body_start].strip().startswith('//')):
                    body_start += 1
                break
        
        if body_start > 0 and body_start <= end_idx:
            # 添加缺少的RT_UNUSED宏
            if not has_argc_unused:
                lines.insert(body_start, "    RT_UNUSED(argc);\n")
                modified = True
            if not has_argv_unused:
                lines.insert(body_start + (1 if not has_argc_unused else 0), "    RT_UNUSED(argv);\n")
                modified = True
        
        if modified:
            self.write_file_content(file_path, lines)
            return True
        
        return False

    def make_function_static(self, file_path: str, line_number: int, function_name: str) -> bool:
        """将非静态函数改为静态函数"""
        lines = self.read_file_content(file_path)
        if not lines:
            return False
        
        line_idx = line_number - 1
        if line_idx >= len(lines):
            return False
        
        original_line = lines[line_idx]
        
        # 如果函数不是静态的，添加static关键字
        if 'static' not in original_line:
            # 查找函数定义行
            func_pattern = r'^\s*(?:inline\s+)?(\w+(?:\s*\*)*)\s+' + re.escape(function_name) + r'\s*\('
            match = re.search(func_pattern, original_line)
            if match:
                # 在返回类型前添加static
                new_line = re.sub(r'^(\s*)', r'\1static ', original_line)
                lines[line_idx] = new_line
                self.write_file_content(file_path, lines)
                return True
        
        return False

    def find_corresponding_header(self, c_file: str) -> Optional[str]:
        """找到对应的头文件"""
        # 尝试同名的.h文件
        base_name = os.path.splitext(c_file)[0]
        header_file = base_name + '.h'
        if os.path.exists(header_file):
            return header_file
        
        # 尝试在include目录中查找
        dir_name = os.path.dirname(c_file)
        include_dir = None
        
        # 向上查找include目录
        current_dir = dir_name
        while current_dir:
            potential_include = os.path.join(current_dir, 'include')
            if os.path.exists(potential_include):
                include_dir = potential_include
                break
            parent = os.path.dirname(current_dir)
            if parent == current_dir:
                break
            current_dir = parent
        
        if include_dir:
            # 在include目录中查找可能相关的头文件
            for root, dirs, files in os.walk(include_dir):
                for file in files:
                    if file.endswith('.h'):
                        return os.path.join(root, file)
        
        return None

    def find_header_declaration(self, header_file: str, function_name: str, return_type: str = None) -> Optional[int]:
        """查找头文件中的函数声明位置"""
        lines = self.read_file_content(header_file)
        if not lines:
            return None
        
        # 构建搜索模式
        if return_type:
            pattern = r'^\s*' + re.escape(return_type) + r'\s+' + re.escape(function_name) + r'\s*\([^)]*\)\s*;'
        else:
            # 匹配任何返回类型
            pattern = r'^\s*\w+(?:\s*\*)*\s+' + re.escape(function_name) + r'\s*\([^)]*\)\s*;'
        
        for i, line in enumerate(lines):
            if re.search(pattern, line):
                return i + 1  # 返回行号（1基）
        
        return None

    def remove_header_declaration(self, header_file: str, function_name: str, return_type: str = None):
        """记录需要从头文件中删除的函数声明"""
        if header_file not in self.header_declarations_to_remove:
            self.header_declarations_to_remove[header_file] = []
        
        line_number = self.find_header_declaration(header_file, function_name, return_type)
        if line_number:
            self.header_declarations_to_remove[header_file].append({
                'function_name': function_name,
                'line_number': line_number,
                'return_type': return_type
            })

    def apply_header_declarations_removal(self):
        """从头文件中删除函数声明"""
        for header_file, declarations in self.header_declarations_to_remove.items():
            lines = self.read_file_content(header_file)
            if not lines:
                continue
            
            # 按行号倒序排列，从后往前删除，避免行号变化
            declarations.sort(key=lambda x: x['line_number'], reverse=True)
            
            removed_count = 0
            for decl in declarations:
                line_idx = decl['line_number'] - 1  # 转换为0基索引
                if 0 <= line_idx < len(lines):
                    del lines[line_idx]
                    removed_count += 1
            
            if removed_count > 0:
                self.write_file_content(header_file, lines)
                print(f"已从 {header_file} 删除 {removed_count} 个函数声明")

    def fix_all_functions(self) -> Dict[str, int]:
        """修复所有不合规的函数"""
        if not self.report_data:
            return {}
        
        stats = {
            'signature_fixed': 0,
            'return_statement_added': 0,
            'rt_unused_added': 0,
            'made_static': 0,
            'header_declarations_removed': 0
        }
        
        for result in self.report_data['results']:
            if not result['is_compliant'] and result['definition']:
                function_info = result['function']
                definition = result['definition']
                issues = result['issues']
                
                file_path = function_info['file']
                function_name = function_info['function_name']
                line_number = definition['line_number']
                return_type = definition.get('return_type', '')
                parameters = definition.get('parameters', '')
                is_static = definition.get('is_static', False)
                
                # 备份文件
                self.backup_file(file_path)
                
                # 修复函数签名
                if any('函数签名不符合规范' in issue for issue in issues):
                    if self.fix_function_signature_comprehensive(file_path, line_number, parameters, return_type):
                        stats['signature_fixed'] += 1
                
                # 将非静态函数改为静态函数
                if not is_static:
                    if self.make_function_static(file_path, line_number, function_name):
                        stats['made_static'] += 1
                    
                    # 记录需要删除的头文件声明
                    header_file = self.find_corresponding_header(file_path)
                    if header_file:
                        self.remove_header_declaration(header_file, function_name, return_type)
                
                # 添加返回语句
                if any('缺少返回语句' in issue for issue in issues):
                    if self.add_return_statement(file_path, function_name, line_number):
                        stats['return_statement_added'] += 1
                
                # 添加RT_UNUSED宏
                if any('未使用且未标记RT_UNUSED' in issue for issue in issues):
                    if self.add_rt_unused_macros(file_path, function_name, line_number):
                        stats['rt_unused_added'] += 1
                
                # 应用头文件声明删除
        self.apply_header_declarations_removal()
        stats['header_declarations_removed'] = sum(len(decls) for decls in self.header_declarations_to_remove.values())
        
        return stats

    def run_checker(self):
        """运行检查脚本"""
        print("正在运行检查脚本...")
        try:
            result = subprocess.run(['python3', 'msh_function_checker.py'], 
                                  capture_output=True, text=True, encoding='utf-8')
            print("检查脚本输出:")
            print(result.stdout)
            if result.stderr:
                print("错误输出:")
                print(result.stderr)
            return result.returncode == 0
        except Exception as e:
            print(f"运行检查脚本失败: {e}")
            return False

    def run(self):
        """运行修复流程"""
        print("=== MSH函数修复工具 ===")
        
        # 1. 恢复文件
        self.restore_files()
        
        # 2. 运行检查脚本生成最新报告
        self.run_checker()
        
        # 3. 加载报告
        if not self.load_report():
            return
        
        # 4. 修复函数
        print("\n开始修复函数...")
        stats = self.fix_all_functions()
        
        print("\n修复统计:")
        for key, value in stats.items():
            print(f"  {key}: {value}")
        
        print(f"\n总共修复了 {sum(stats.values())} 个问题")
        print(f"修改了 {len(self.fixed_files)} 个文件")
        
        # 5. 运行检查
        print("\n运行检查脚本验证修复结果...")
        self.run_checker()

if __name__ == "__main__":
    fixer = MSHFunctionFixer()
    fixer.run()
