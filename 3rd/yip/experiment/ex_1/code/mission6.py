"""
任务6：在父进程中设置一个死循环，通过Linux 命令的查看进程命令，检查子进程是否变成僵尸进程
"""

import os
import time

parent = os.getpid()
print(f"父进程ID：{parent}")


# 创建子进程1
os.fork()

if os.getpid() == parent:  # 限定只有主进程才能创建子进程
    os.fork()  # 创建子进程2

time.sleep(20)  # 每个进程都停止20秒以观测

# 给父进程设置死循环
pid = os.getpid()
if pid == parent:
    while 1:
        pass
    os.wait()

