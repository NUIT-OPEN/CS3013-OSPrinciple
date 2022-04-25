# Ex0

Linux内核模块编程

## 第一部分

* 编写内核模块代码
  * 参见[simple.c](simple.c) 

* 编写Makefile以构建内核模块
  * 参见[Makefile](Makefile)

* 编译内核模块

```log
root@ubuntu-linux-20-04-desktop:~# make
make -C /usr/src/linux-headers-5.13.0-25-generic/ M=/root  modules
make[1]: Entering directory '/usr/src/linux-headers-5.13.0-25-generic'
make[1]: Leaving directory '/usr/src/linux-headers-5.13.0-25-generic'
root@ubuntu-linux-20-04-desktop:~# 
```

* 加载与卸载内核模块

```log
root@ubuntu-linux-20-04-desktop:~# insmod simple.ko 
root@ubuntu-linux-20-04-desktop:~# dmesg 
[12888.096990] simple loaded.
root@ubuntu-linux-20-04-desktop:~# rmmod simple
root@ubuntu-linux-20-04-desktop:~# dmesg 
[12888.096990] simple loaded.
[12911.120234] simple exited.
root@ubuntu-linux-20-04-desktop:~# 
```
