"""
任务1： 在 main 父进程创建两个子进程，两个子进程不编写代码，运行并查看效果
"""

import os
import time

parent = os.getpid()
print(f"父进程ID：{parent}")


# 创建子进程1
os.fork()

if os.getpid() == parent:  # 限定只有主进程才能创建子进程
    os.fork()  # 创建子进程2

time.sleep(20)
