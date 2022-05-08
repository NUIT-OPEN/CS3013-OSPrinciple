# Ex4

* 信号量与PV操作实现

## 任务一 & 任务二

在main函数下创建两个线程，一个线程为生产者线程,一个线程为消费者线程.

通过编程实现单缓冲区的生产者和消费者问题，通过观察实验结果分析信号量机制在同步与互斥中的实现原理。

* 代码：参见[signal.c](signal.c)

* 运行结果

```log
parallels@ubuntu-linux-20-04-desktop:~/Downloads$ ./a.out 
Input message>>
123
Produce item is>>123
Input message>>
Consume item is<<123
abc
Produce item is>>abc
Input message>>
Consume item is<<abc
^C
parallels@ubuntu-linux-20-04-desktop:~/Downloads$
```

## 任务三

定义两个进程，一个进程为生产者，一个进程为消费者，能不能用进程来模拟单缓冲区的生产者和消费者问题?为什么?

* 答：能，虽然两个进程之间内存数据不共享，但是可以通过使用文件的方式进行数据共享以实现信号的传递。
