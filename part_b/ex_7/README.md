# Ex7

文件系统编程

## 任务1

设计一个程序打开“/etc/passwd”文件，依次读取每行内容并打印该内容。

* 代码实现：参见[m1.c](m1.c)

* 运行结果

```log
ubuntu@primary:ex_7$ gcc m1.c && ./a.out 
line 1: root:x:0:0:root:/root:/bin/bash
line 2: daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
line 3: bin:x:2:2:bin:/bin:/usr/sbin/nologin
line 4: sys:x:3:3:sys:/dev:/usr/sbin/nologin
line 5: sync:x:4:65534:sync:/bin:/bin/sync
...以下省略若干行...
```

## 任务2

设计一个程序打开“/etc/passwd”文件，将第2行至第5行存到文件./qq.txt中，并打印该内容。

* 代码实现：参见[m2.c](m2.c)

* 运行结果

```log
ubuntu@primary:ex_7$ gcc m2.c && ./a.out 
ubuntu@primary:ex_7$ cat qq.txt 
line 2: daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
line 3: bin:x:2:2:bin:/bin:/usr/sbin/nologin
line 4: sys:x:3:3:sys:/dev:/usr/sbin/nologin
line 5: sync:x:4:65534:sync:/bin:/bin/sync
```

## 任务3

以只读方式打开系统配置文件“/etc/passwd”，并读取打印出前100个字符。

* 代码实现：参见[m3.c](m3.c)

* 运行结果

```log
ubuntu@primary:ex_7$ gcc m3.c && ./a.out 
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/
ubuntu@primary:ex_7$ 
```

## 任务4

设计一个程序打开当前目录下文件“./test2”并写入 “Hello,welcome to hustwenhua!”字符串。

* 代码实现：参见[m4.c](m4.c)

* 运行结果

```log
ubuntu@primary:ex_7$ gcc m4.c && ./a.out 
ubuntu@primary:ex_7$ cat test2 
Hello,welcome to hustwenhua!
ubuntu@primary:ex_7$
```

## 任务5

设计一个程序打开“/etc/passwd”文件，计算文件长度，并一次性读取文件所有内容后打印该内容。

* 代码实现：参见[m5.c](m5.c)

* 运行结果

```log
ubuntu@primary:ex_7$ gcc m5.c && ./a.out 
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/usr/sbin/nologin
sys:x:3:3:sys:/dev:/usr/sbin/nologin
sync:x:4:65534:sync:/bin:/bin/sync
games:x:5:60:games:/usr/games:/usr/sbin/nologin
...以下省略若干行...
total file size: 1760
```
