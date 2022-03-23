"""
任务2： 在 main 父进程创建两个子进程，分别输出两个子进程与父进程的ID 号
"""

import os
import time

parent = os.getpid()
print(f"父进程ID：{parent}")


# 创建子进程1
os.fork()

if os.getpid() == parent:  # 限定只有主进程才能创建子进程
    os.fork()  # 创建子进程2

# 输出子进程的 ID 号及其父进程 ID 号
pid = os.getpid()
if pid != parent:
    print(f"该进程为子进程，ID：{pid}，父进程 ID：{os.getppid()}")

