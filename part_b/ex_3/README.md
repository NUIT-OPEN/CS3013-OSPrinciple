# Ex3

* 进程的管道通信

## 任务一

使用Pipe创建管道，创建一个子进程，子进程向父进程发送消息“I am your son!”,父进程接收到子进程的消息后，显示在屏幕上，并向子进程发送“I am your father!”。子进程接收到父进程的消息并显示在屏幕上。

* 代码：参见[m1.c](m1.c)

* 运行结果

```log
parallels@ubuntu-linux-20-04-desktop:~/Downloads/proc_pipe$ ./m1
[parent] recv: I am your son!
[child] recv: I am your father!
```

## 任务二

使用系统调用 pipe ( ) 建立一条管道线；两个子进程 P1 和 P2 分别向管道各写一句话 Child 1 is sending a message!
Child 2 is sending a message！ 而父进程则从管道中读出来自于两个子进程的信息，显示在屏幕上。

* 代码：参见[m2.c](m2.c)

* 运行结果

```log
parallels@ubuntu-linux-20-04-desktop:~/Downloads/proc_pipe$ ./m2
[parent] recv: Child 1 is sending a message!
[parent] recv: Child 2 is sending a message!
```

## 任务三

能否创建一条管道，实现两个子进程之间的通信，如果可以，请实现并给出代码。如果不可以，请说明理由

* 代码：参见[m3.c](m3.c)

* 运行结果

```log
parallels@ubuntu-linux-20-04-desktop:~/Downloads/proc_pipe$ ./m3
[child_2] recv: Child 1 is sending a message!
```
