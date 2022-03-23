"""
任务4：在main 父进程创建两个子进程，分别在父进程与子进程设置循环输出，查看运行结果，并分析原因
"""

import os
import time

parent = os.getpid()
print(f"父进程ID：{parent}")


# 创建子进程1
os.fork()

if os.getpid() == parent:  # 限定只有主进程才能创建子进程
    os.fork()  # 创建子进程2

# 设置 name 标识，区分父子进程
name = "主进程" if os.getpid() == parent else "子进程"

# 设置循环，该循环三个进程都会执行

for i in range(10):
    time.sleep(1)  # 停1秒，以观测
    print(f"{name} 执行打印: {i}")

# 守护进程
pid = os.getpid()

if pid == parent:
    os.wait()

