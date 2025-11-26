#!/usr/bin/env python3
import os
import re

def check_fixed_functions():
    """检查已修复的函数"""
    fixed_files = [
        '/mnt/d/Develop/rt-thread/src/mem.c',
        '/mnt/d/Develop/rt-thread/src/memheap.c', 
        '/mnt/d/Develop/rt-thread/components/finsh/cmd.c',
        '/mnt/d/Develop/rt-thread/components/utilities/ymodem/ry_sy.c',
        '/mnt/d/Develop/rt-thread/examples/test/ringbuffer_test.c',
        '/mnt/d/Develop/rt-thread/bsp/wch/arm/Libraries/ch32_drivers/drv_common.c',
        '/mnt/d/Develop/rt-thread/libcpu/arm/cortex-a/gic.c',
        '/mnt/d/Develop/rt-thread/libcpu/aarch64/common/interrupt.c'
    ]
    
    print("=== 检查已修复的MSH函数签名 ===\n")
    
    for file_path in fixed_files:
        if not os.path.exists(file_path):
            continue
            
        print(f"检查文件: {file_path}")
        
        try:
            with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read()
                
            # 查找MSH_CMD_EXPORT
            msh_matches = re.finditer(r'MSH_CMD_EXPORT(_ALIAS)?\s*\(\s*(\w+)', content)
            
            for match in msh_matches:
                func_name = match.group(2)
                
                # 在MSH_CMD_EXPORT之前查找函数定义
                func_pattern = rf'(static\s+)?(?:int|void|long|rt_err_t)\s+{func_name}\s*\([^)]*\)'
                func_match = re.search(func_pattern, content[:match.start()])
                
                if func_match:
                    func_def = func_match.group(0)
                    print(f"  函数: {func_name}")
                    print(f"  签名: {func_def}")
                    
                    # 检查是否符合标准
                    if re.match(r'(?:static\s+)?int\s+\w+\s*\(\s*int\s+argc\s*,\s*char\s*\*\*\s*argv\s*\)', func_def):
                        print("  ✓ 签名正确")
                    else:
                        print("  ✗ 签名不正确")
                    print()
                    
        except Exception as e:
            print(f"  错误: {e}\n")

if __name__ == '__main__':
    check_fixed_functions()
