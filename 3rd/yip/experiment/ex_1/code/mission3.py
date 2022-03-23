"""
任务3：在任务2的基础上，在父进程中共设置 wait 函数，等待子进程结束，
分别对比与任务2的结果有什么区别，并进行分析。
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

if pid == parent:  # 守护进程
    os.wait()

