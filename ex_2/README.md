# Ex2

进程的创建和控制

## 任务一

在main父进程创建两个子进程，两个子进程不编写自己的代码，编译运行查看效果。

* 代码：参见[m1.c](m1.c)

* 运行结果

```log
parallels@ubuntu-linux-20-04-desktop:~/Downloads$ ./m1
a=3parallels@ubuntu-linux-20-04-desktop:~/Downloads$ a=3a=3a=3
parallels@ubuntu-linux-20-04-desktop:~/Downloads$ 
```

## 任务二

在main父进程创建两个子进程，分别输出两个子进程与父进程的id号。

* 代码：参见[m2.c](m2.c)

* 运行结果

```c
parallels@ubuntu-linux-20-04-desktop:~/Downloads$ ./m2 
parent id: 95710
parallels@ubuntu-linux-20-04-desktop:~/Downloads$ child_2 id: 95712
child_1 id: 95711

parallels@ubuntu-linux-20-04-desktop:~/Downloads$ 
```

## 任务三

在任务2的基础上，在父进程中设置wait西数，等待子进程结束；分别对比气任务3的结果有什么区别，并进行分析。

* 代码：参见[m3.c](m3.c)

* 运行结果

```log
parallels@ubuntu-linux-20-04-desktop:~/Downloads$ ./m3 
parent id: 96149
child_1 id: 96150
child_2 id: 96151
parallels@ubuntu-linux-20-04-desktop:~/Downloads$ 
```

## 任务四

在main父进程创建两个子进程，分别在父进程与子进程设置循环输出，查看运行结果，并分析原因

* 代码：参见[m4.c](m4.c)

* 运行结果

```log
Son 0Son 1Son 2Son 3Son 4Son 5Son 6Son 7Son 8Son 9Son 10Son 11Son 12Son 13Son 14Son 15Son 16Son 17Son 18Son 19Son 20Son 21Son 22Son 23Son 24Son 25Son 26Son 27Son 28Son 29Son 30Son 31Son 32Son 33Son 34Son 35Son 36Son 37Son 38Son 39Son 40Son 41Son 42Son 43Son 44Son 45Son 46Son 47Son 48Son 49Daughter 0Daughter 1Daughter 2Daughter 3Daughter 4Daughter 5Daughter 6Daughter 7Daughter 8Daughter 9Daughter 10Daughter 11Daughter 12Daughter 13Daughter 14Daughter 15Daughter 16Daughter 17Daughter 18Daughter 19Daughter 20Daughter 21Daughter 22Daughter 23Daughter 24Daughter 25Daughter 26Daughter 27Daughter 28Daughter 29Daughter 30Daughter 31Daughter 32Daughter 33Daughter 34Daughter 35Daughter 36Daughter 37Daughter 38Daughter 39Daughter 40Daughter 41Daughter 42Daughter 43Daughter 44Daughter 45Daughter 46Daughter 47Daughter 48Daughter 49Father 0Father 1Father 2Father 3Father 4Father 5Father 6Father 7Father 8Father 9Father 10Father 11Father 12Father 13Father 14Father 15Father 16Father 17Father 18Father 19Father 20Father 21Father 22Father 23Father 24Father 25Father 26Father 27Father 28Father 29Father 30Father 31Father 32Father 33Father 34Father 35Father 36Father 37Father 38Father 39Father 40Father 41Father 42Father 43Father 44Father 45Father 46Father 47Father 48Father 49parallels@ubuntu-linux-20-04-desktop:~/Downloads$ 
```

## 任务五

在任务4的基础上，使用lockf函数进行资源锁定。

* 代码：参见[m5.c](m5.c)

* 运行结果

```log
parallels@ubuntu-linux-20-04-desktop:~/Downloads$ ./m5 
Son 0Son 1Son 2Son 3Son 4Son 5Son 6Son 7Son 8Son 9Son 10Son 11Son 12Son 13Son 14Son 15Son 16Son 17Son 18Son 19Son 20Son 21Son 22Son 23Son 24Son 25Son 26Son 27Son 28Son 29Son 30Son 31Son 32Son 33Son 34Son 35Son 36Son 37Son 38Son 39Son 40Son 41Son 42Son 43Son 44Son 45Son 46Son 47Son 48Son 49Daughter 0Daughter 1Daughter 2Daughter 3Daughter 4Daughter 5Daughter 6Daughter 7Daughter 8Daughter 9Daughter 10Daughter 11Daughter 12Daughter 13Daughter 14Daughter 15Daughter 16Daughter 17Daughter 18Daughter 19Daughter 20Daughter 21Daughter 22Daughter 23Daughter 24Daughter 25Daughter 26Daughter 27Daughter 28Daughter 29Daughter 30Daughter 31Daughter 32Daughter 33Daughter 34Daughter 35Daughter 36Daughter 37Daughter 38Daughter 39Daughter 40Daughter 41Daughter 42Daughter 43Daughter 44Daughter 45Daughter 46Daughter 47Daughter 48Daughter 49Father 0Father 1Father 2Father 3Father 4Father 5Father 6Father 7Father 8Father 9Father 10Father 11Father 12Father 13Father 14Father 15Father 16Father 17Father 18Father 19Father 20Father 21Father 22Father 23Father 24Father 25Father 26Father 27Father 28Father 29Father 30Father 31Father 32Father 33Father 34Father 35Father 36Father 37Father 38Father 39Father 40Father 41Father 42Father 43Father 44Father 45Father 46Father 47Father 48Father 49parallels@ubuntu-linux-20-04-desktop:~/Downloads$ 
```
