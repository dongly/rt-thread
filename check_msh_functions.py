#!/usr/bin/env python3
import os
import re
import subprocess

def find_files_with_msh_cmd_export(root_dir):
    """Find all C files containing MSH_CMD_EXPORT"""
    cmd = ['find', root_dir, '-name', '*.c', '-exec', 'grep', '-l', 'MSH_CMD_EXPORT', '{}', ';']
    result = subprocess.run(cmd, capture_output=True, text=True)
    return result.stdout.strip().split('\n') if result.stdout.strip() else []

def extract_function_signatures(file_path):
    """Extract function signatures and MSH_CMD_EXPORT lines"""
    try:
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
    except:
        return []
    
    lines = content.split('\n')
    functions = []
    
    # Find function definitions before MSH_CMD_EXPORT
    for i, line in enumerate(lines):
        if 'MSH_CMD_EXPORT' in line:
            # Extract function name from MSH_CMD_EXPORT
            match = re.search(r'MSH_CMD_EXPORT[_ALIAS]*\s*\(\s*(\w+)', line)
            if match:
                func_name = match.group(1)
                
                # Look backwards for function definition
                for j in range(i-1, max(0, i-50), -1):
                    line_content = lines[j].strip()
                    # Skip empty lines and comments
                    if not line_content or line_content.startswith('/*') or line_content.startswith('//') or line_content.startswith('*'):
                        continue
                    
                    # Function definition pattern
                    func_pattern = rf'^(static\s+)?(int|void|long|rt_err_t)\s+{func_name}\s*\([^)]*\)'
                    if re.search(func_pattern, line_content):
                        functions.append({
                            'file': file_path,
                            'line': j + 1,
                            'signature': line_content,
                            'export_line': i + 1,
                            'export_content': line.strip()
                        })
                        break
    
    return functions

def check_function_signature(signature):
    """Check if function signature matches the expected pattern"""
    # Expected pattern: int (*cmd_function_t)(int argc, char **argv)
    expected_pattern = r'^(static\s+)?int\s+\w+\s*\(\s*int\s+argc\s*,\s*char\s*\*\*\s*argv\s*\)'
    
    issues = []
    
    # Check return type
    if not signature.strip().startswith('int') and not signature.strip().startswith('static int'):
        if 'void' in signature:
            issues.append("返回类型应该是int而不是void")
        else:
            issues.append(f"返回类型应该是int，当前是: {signature.split()[0] if signature.split() else 'unknown'}")
    
    # Check parameter types
    if 'int argc' not in signature or 'char **argv' not in signature:
        if 'void' in signature:
            issues.append("参数应该是(int argc, char **argv)而不是void")
        else:
            # Extract parameters
            params_match = re.search(r'\(([^)]*)\)', signature)
            if params_match:
                params = params_match.group(1).strip()
                if params != 'int argc, char **argv' and params != 'int argc,char**argv':
                    issues.append(f"参数应该是(int argc, char **argv)，当前是: ({params})")
    
    return issues

def main():
    root_dir = '/mnt/d/Develop/rt-thread'
    files = find_files_with_msh_cmd_export(root_dir)
    
    all_issues = []
    
    for file_path in files:
        if not os.path.exists(file_path):
            continue
            
        functions = extract_function_signatures(file_path)
        
        for func in functions:
            issues = check_function_signature(func['signature'])
            
            if issues:
                all_issues.append({
                    'file': func['file'],
                    'line': func['line'],
                    'signature': func['signature'],
                    'export_line': func['export_line'],
                    'export_content': func['export_content'],
                    'issues': issues
                })
    
    # Print report
    print(f"RT-Thread MSH_CMD_EXPORT 函数签名检查报告")
    print("=" * 80)
    print(f"总共检查了 {len(files)} 个文件")
    print(f"发现 {len(all_issues)} 个问题函数")
    print("=" * 80)
    
    for i, issue in enumerate(all_issues, 1):
        print(f"\n{i}. 文件: {issue['file']}")
        print(f"   行号: {issue['line']}")
        print(f"   函数签名: {issue['signature']}")
        print(f"   导出宏: {issue['export_content']} (行号: {issue['export_line']})")
        print("   问题:")
        for j, problem in enumerate(issue['issues'], 1):
            print(f"     {j}) {problem}")
    
    if all_issues:
        print(f"\n总结: 发现 {len(all_issues)} 个函数需要修改")
    else:
        print("\n总结: 所有函数都符合要求")

if __name__ == '__main__':
    main()