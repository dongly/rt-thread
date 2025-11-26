#!/usr/bin/env python3
import os
import re
import glob

def find_msh_functions(root_dir):
    """查找所有使用MSH_CMD_EXPORT的函数"""
    issues = []
    
    for root, dirs, files in os.walk(root_dir):
        # 跳过一些目录
        if '.git' in root or 'documentation' in root:
            continue
            
        for file in files:
            if file.endswith('.c'):
                file_path = os.path.join(root, file)
                try:
                    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                        content = f.read()
                        
                    # 查找MSH_CMD_EXPORT行
                    msh_matches = re.finditer(r'MSH_CMD_EXPORT(_ALIAS)?\s*\(\s*(\w+)', content)
                    
                    for match in msh_matches:
                        func_name = match.group(2)
                        
                        # 在MSH_CMD_EXPORT之前查找函数定义
                        # 查找函数定义模式
                        func_pattern = rf'(?:(?:static|extern)?\s*(?:int|void|long|rt_err_t)\s+{func_name}\s*\([^)]*\))'
                        func_match = re.search(func_pattern, content[:match.start()])
                        
                        if func_match:
                            func_def = func_match.group(0)
                            
                            # 检查各种问题
                            issues.append({
                                'file': file_path,
                                'func_name': func_name,
                                'func_def': func_def,
                                'full_match_start': match.start(),
                                'full_match_end': match.end()
                            })
                            
                except Exception as e:
                    print(f"Error processing {file_path}: {e}")
    
    return issues

def analyze_function_issues(issues):
    """分析函数问题"""
    analysis = {
        'return_type_issues': [],
        'param_type_issues': [],
        'param_format_issues': [],
        'correct_functions': []
    }
    
    for issue in issues:
        func_def = issue['func_def']
        
        # 检查返回类型
        if 'void' in func_def.split('(')[0]:
            analysis['return_type_issues'].append(issue)
        elif 'long' in func_def.split('(')[0] or 'rt_err_t' in func_def.split('(')[0]:
            analysis['return_type_issues'].append(issue)
            
        # 检查参数类型
        if 'void)' in func_def:
            analysis['param_type_issues'].append(issue)
        elif 'uint8_t argc' in func_def:
            analysis['param_type_issues'].append(issue)
        elif 'char *argv[]' in func_def:
            analysis['param_format_issues'].append(issue)
        else:
            # 检查是否已经是正确的格式
            if re.match(r'(?:static\s+)?int\s+\w+\s*\(\s*int\s+argc\s*,\s*char\s*\*\*\s*argv\s*\)', func_def):
                analysis['correct_functions'].append(issue)
            else:
                analysis['param_type_issues'].append(issue)
    
    return analysis

def main():
    root_dir = '/mnt/d/Develop/rt-thread'
    
    print("正在查找MSH函数...")
    issues = find_msh_functions(root_dir)
    print(f"找到 {len(issues)} 个MSH函数")
    
    print("正在分析函数问题...")
    analysis = analyze_function_issues(issues)
    
    print(f"\n=== 分析结果 ===")
    print(f"返回类型问题: {len(analysis['return_type_issues'])}")
    print(f"参数类型问题: {len(analysis['param_type_issues'])}")
    print(f"参数格式问题: {len(analysis['param_format_issues'])}")
    print(f"正确函数: {len(analysis['correct_functions'])}")
    
    # 显示一些示例
    if analysis['return_type_issues']:
        print(f"\n=== 返回类型问题示例 ===")
        for issue in analysis['return_type_issues'][:5]:
            print(f"{issue['file']}: {issue['func_def']}")
    
    if analysis['param_type_issues']:
        print(f"\n=== 参数类型问题示例 ===")
        for issue in analysis['param_type_issues'][:5]:
            print(f"{issue['file']}: {issue['func_def']}")

if __name__ == '__main__':
    main()