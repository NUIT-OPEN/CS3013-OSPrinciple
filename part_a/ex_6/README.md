# Ex6

文件系统编程

## 文件内容拷贝

设计程序，要求从一源文件src_file（若不存在则创建）中读取倒数第二个10KB数据复制到目标文件dest_file。

(a) 程序要求从源文件读取倒数第二个10KB数据，首先需要以只读方式打开源文件，并把读取位置定位到距离文件末尾倒数第二个10KB的起始位置，然后读取10KB的内容到buf中。

(b) 以只写方式打开目标文件，并把读取到的10KB数据写入目标文件中。

(c) 可采取每次读取1KB数据并写入目标文件，重复10次读写操作完成程序功能。

* 代码参见：[m1.c](m1.c)

* 运行结果

```log
ubuntu@primary:ex_6$ gcc m1.c && ./a.out 
ubuntu@primary:ex_6$ ll
total 144
drwxr-xr-x 1 ubuntu ubuntu    256 Jun  8 16:39 ./
drwxr-xr-x 1 ubuntu ubuntu    288 Jun  6 15:15 ../
-rw-r--r-- 1 ubuntu ubuntu   1078 Jun  8 14:57 README.md
-rwxrwxr-x 1 ubuntu ubuntu   9400 Jun  8 16:39 a.out*
-rw-r--r-- 1 ubuntu ubuntu  10240 Jun  8 16:39 dest_file
-rw-r--r-- 1 ubuntu ubuntu    356 Jun  8 16:38 m1.c
-rw-r--r-- 1 ubuntu ubuntu     49 Jun  8 14:52 m2.c
-rw-rw-r-- 1 ubuntu ubuntu 100000 Jun  8 14:53 src_file
ubuntu@primary:ex_6$ 
```

## 字符串文件内容解析

通过系统文件/etc/passwd，解析本系统共计有哪些用户，并把所有用户的用户名写入本地文件test5中。

(a) 分别按只读和可写的方式打开两个文件 

(b) 使用fgets函数依次读取/etc/passwd文件中的每行数据（由该文件格式可知：每行包含一个用户信息）

(c) 根据文件格式（首个冒号前的字符串即为用户名）分析系统用户名称，并打印

* 代码参见：[m2.c](m2.c)

* 运行结果

```log
ubuntu@primary:ex_6$ gcc m2.c && ./a.out 
root daemon bin sys sync games man lp mail news uucp proxy www-data backup list irc gnats nobody systemd-network systemd-resolve systemd-timesync messagebus syslog _apt tss uuidd tcpdump sshd landscape pollinate systemd-coredump ubuntu lxd
ubuntu@primary:ex_6$ cat test5 
root
daemon
bin
sys
sync
games
man
lp
mail
news
uucp
proxy
www-data
backup
list
irc
gnats
nobody
systemd-network
systemd-resolve
systemd-timesync
messagebus
syslog
_apt
tss
uuidd
tcpdump
sshd
landscape
pollinate
systemd-coredump
ubuntu
lxd
ubuntu@primary:ex_6$ 
```
