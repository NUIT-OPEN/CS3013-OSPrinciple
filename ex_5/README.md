# Ex5

* Linux多线程创建

> 注意：对应线程库的函数，需要在编译的时候进行链接，也就是需要在原来的gcc编译命令后面加上-lpthread

## 任务一

在main函数中创建两个子线程，两个子线程的函数为child1和child2

* 代码实现：参见[m1.c](m1.c)
* 运行结果

```log
This is child 1.
This is child 2.
```

## 任务二

在两个子线程函数中分别输出两个子线程id，并在child2中定义一个私有变量a=(学号后3位)，修改线程私有变量为a=(19+学号后3位)

* 代码实现：参见[m2.c](m2.c)
* 运行结果

```log
[6090551296] This is child 1.
[6091124736] This is child 2.
[define] a = <stu_number_define>
[modify] a = <stu_number_modify>
```

## 任务三

能否在child1中对其child2的私有变量进行修改，为什么？
> 答：不能，因为线程私有变量在不同的线程中各自持有不同的值

* 代码实现：参见[m3.c](m3.c)
* 运行结果

```log
[6128381952] This is child 1.
[child1] a = 123
[6128381952] This is child 2.
[child2] a = (null)
```

## 任务四

在main函数中，要求main函数等待两个子线程的结束，注销线程的私有的数据。

* 代码实现：参见[m4.c](m4.c)
* 运行结果

```log
[6122500096] This is child 1.
[child1] a = child1
[6123073536] This is child 2.
[child2] a = child2
```

## 任务五

完成课本上第119页图4-9 的线程创建练习，掌握带参数传递的线程创建方法。

* 代码实现：参见[m5.c](m5.c)
* 运行结果

```log
Transfer Parameter: Test content.
```
