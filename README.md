# Embedded-written-reference
+ 2019-参加过的嵌入式笔试题目和解析分享

## Content

   * [Embedded-written-reference](#embedded-written-reference)
   + [Table of Contents](#table-of-contents)
      * [诺瓦科技](#诺瓦科技)
         * [7.30笔试题](#730笔试题)
         * [8.12 面试题(胡HR)](#812-面试题胡hr)
      * [8.1号大疆嵌入式参考](#81号大疆嵌入式参考)
         * [8.4 大疆笔试](#84-大疆笔试)
         * [8.15 大疆初面](#815-大疆初面)
      * [8.3网易笔试](#83网易笔试)
      * [TCP/IP](#tcpip)
      * [C语言](#c语言)
      * [shell](#shell)
      * [dataStruct](#datastruct)
      * [OS](#os)
         * [Linux 中断](#linux-中断)
         * [Linux 驱动](#linux-驱动)
         * [Operate System](#operate-system)

## 诺瓦科技

### 7.30笔试题

1. [系统外围驱动（I2C、SPI、UART、485）和应用的编程?](https://luckywater.top/2019/07/29/SerialBus/)
2. [ARM 指令集可以分为哪六大类?](https://luckywater.top/2019/08/02/ARM体系结构/)
3. [ARM体系结构中的工作状态?](https://luckywater.top/2019/08/02/ARM体系结构/)
4. ARM 和EEPROM之间的通信方式是什么?当时有两个电阻没有焊接出错, 后面焊接完成就正确了?
   - 两个电阻属于上拉电阻; I2C的通信方式
5. [Linux的**用户态与内核态 **?](https://luckywater.top/2019/08/02/linux用户和内核/)
   1. Linux的用户态与内核态 定义?
   2. Linux的用户态与内核态 **如何切换**的? 
   3. Linux的用户态与内核态的**通信**方式?
6. [linux内核裁剪的方式?](/7.30诺瓦科技/linux内核裁剪的方式.md)
7. *未全部完成 --*    [进程间通信有哪几种方式?](https://luckywater.top/2019/08/02/进程间通信的几种方式/)
   1. 为什么进程间通信需要**内核**?
   2. 编程题: 进程间通信通过管道pipe实现?
8. [英文翻译: 关于时钟发生器的英文翻译?](/7.30诺瓦科技/关于时钟发生器的英文翻译.md)
9. [编程题: 通过互斥量实现线程间的通信?]
   + 上次笔试没有做出来, 面试的时候会问, 所以笔试完了后应该去做一做.

### 8.12 面试题(胡HR)

+ 缺点: 回答的太官方了, 只有理论没有具体实践;
+ 主要是分为两大块: 外设通信方式, Linux系统的问题;

1. [示波器采集数据的要求?](7.30诺瓦科技/示波器采集数据的要求.md)
3. Linux的具体的命令, 文件操作的5个命令?
4. Makefile文件的编写?
6. [TCP/IP物理层的具体内容是啥?](7.30诺瓦科技/tcp物理层的具体内容.md)
7. 驱动这款需要看, Uboot需要去看一下?
   + 网络驱动和字符驱动
8. 简历上项目的具体问题?
   + 建立要写明确具体用的方式和处理细节?
   + 用的主控, 和主控间的通信方式?



## 8.1号大疆嵌入式参考

+ [参考](https://blog.csdn.net/qq_38410730/article/details/80951443)

1. [TCP与UDP的区别?](https://luckywater.top/2019/05/06/TcpIp/)
2. [OS**内存字节对齐** pragma pack()用法详解?](https://luckywater.top/2019/08/02/PragmaPack/)
   1. 32位/64位的系统中, 各自的sizeof()是多少?
   2. 数据类型间的混合运算, 最后的输出?
3. [OS大端和小端存储问题问题?](/8.1Dji大疆/大端小端存储问题.md)
4. [OS无锁可以提高整个程序的性能，但是CPU需要对此提供支持，请以x86/ARM为例简述](/8.1Dji大疆/cpu对锁的支持.md)
5. [OS多任务嵌入式系统中，将寄存器REGn的指定位反转](/8.1Dji大疆/OS嵌入式系统指定位反转.md)
7. [OS简述 处理器读取内存的过程](/8.1Dji大疆/OS处理器读取内存的过程.md)
8. [OS系统设计]
10. [OS 如何实现进程间的切换?](/8.1Dji大疆/OS如何实现进程间的切换.md)
11. [C语言的**各种变量的存取区域**，给你一段小程序，让你分析各个变量的存储区域?](/8.1Dji大疆/C变量存储区域.md)
12. [C中使用memcpy()系列函数时要足够小心?](/8.1Dji大疆/C函数使用注意.md)
13. [C语言**编译执行**的四个阶段?](/8.1Dji大疆/C语言编译执行的四个阶段.md)
14. [C简述实时操作系统和非实时操作系统特点和区别?](/8.1Dji大疆/OS实时和非实时性.md)
15. [简述**C函数中参数**传递问题](/8.1Dji大疆/简述C函数中参数传递问题.md)
16. [linux**目录结构**，选项是/usr、/tmp、/etc目录的作用?](/8.1Dji大疆/linux目录结构.md)
17. [linux系统打开设备文件，进程可能处于三种基本状态?如果多次打开设备文件，驱动程序应该实现什么?](/8.1Dji大疆/linux系统打开设备文件处于的状态.md)
18. *未全部完成 --*[Linux内核中常用的两个宏定义?](/8.1Dji大疆/linux内核中常用的两个宏定义.md)
19. [Online Judge:  实现一个循环缓冲区.](https://github.com/quronghui/DataStructAndAlogrithmCode/blob/master/CompanyWrite/1_Dji/circularReadWrite.c)

### 8.4 大疆笔试

1.  [C : 当char类型变量进行赋值时, 超过其范围时怎么处理?](https://github.com/quronghui/DataStructAndAlogrithmCode/blob/master/CompanyWrite/1_Dji/charConvertint.c)
2. [C: 有符号的变量(负数)和无符号的变量(正数)相加](/8.1Dji大疆/C有符号的变量和无符号的变量相加.md)
3.  [C: 关键字用途的描述](/8.1Dji大疆/C关键词的描述.md)
4.  [C: 如何实现一个数的四舍五入?]
5.  [OS 结构体和联合体的**内存字节**对齐计算?](https://luckywater.top/2019/08/02/PragmaPack/)
6.  *未全部完成 --* [OS并发: 可以通过哪些方法进行同步?](/8.1Dji大疆/OS并发的同步机制.md)
7.  [OS 简述一个执行程序在运行时的内存布局?]( /8.1Dji大疆/OS简述一个执行程序在运行时的内存布局.md)
8.  [OS简述线程之间的同步互斥时占用空间的大小]( /8.1Dji大疆/OS简述线程之间的同步互斥时占用空间的大小.md)
9.  [Online Judge :  忽略字母大小写的差异, 实现字符串比较? ](https://github.com/quronghui/DataStructAndAlogrithmCode/blob/master/CompanyWrite/1_Dji/strncmp.c)

### 8.15 大疆初面

1. 自我介绍和项目的描述?
2. [OS cache缓存一致性描述?](/8.1Dji大疆/OScache缓存一致性描述.md)
3. [OS cache(页面)多任务调度描述?](/8.1Dji大疆/OScache多任务调度描述.md)
4. [Linux 多任务, 进程, 线程之间的关系?](/8.1Dji大疆/Linux多任务进程线程之间的关系.md)
5. [Linux查询进程和线程数量?](/8.1Dji大疆/Linux查询进程和线程数量.md)
6. *未全部完成 --[嵌入式实时操作系统描述?](/8.1Dji大疆/OS嵌入式实时操作系统描述.md)
7. 做过一些驱动开发吗?
   + [参考](https://www.jianshu.com/p/716ed9cdb8f3)

## 8.3网易笔试

1. [Linux 系统权限755 777 644 ?](/8.3网易/LInux系统权限.md)
2. 没做出来 -- [echo 重定义 和 grep 正则表达式匹配](/8.3网易/echo重定义和grep正则表达式匹配.md)
3. [Dijkstra最短路径算法的描述正确的是?](/8.3网易/Dijkstra最短路径算法的描述.md)
4. [TCP IP 数据传输中, 数据如何进行分包?](/8.3网易/TCPIP数据分包.md)
5. [二叉树8个度为2节点, 5个度为1节点 , 度为0有多少个节点?](/8.3网易/二叉树节点和度.md)

## TCP/IP

1. [DNS服务器是如何工作的?](/TCP/DNS服务器是如何工作的.md)
2. [OSI七层中的硬件设备](/TCP/OSI七层中的硬件设备.md)
3. [TCP三次握手和四次挥手](/TCP/TCP三次握手和四次挥手.md)
4. [Socket建立连接过程](/TCP/Socket建立连接过程.md)
5. [http和TCP之间的关联, http建立链接的过程?](/TCP/http和TCP之间的关联.md)
6. [https怎么保证安全的？讲讲数字签名的过程]

## C语言

1. [C指针和引用的区别?](/C/指针和引用的区别.md)
2. [C变量的生命周期?](/C/C变量的生命周期.md)
3. [C什么是左值，什么是右值]

## shell

1. [Linux把名称中含有test内容的进程找出来杀死?](/shell/Linux把名称中含有test内容的进程找出来杀死.md)
2. [Linux读取某个文件的某一行或者某几行, 使用sed](/shell/Linux读取某个文件的某一行或者某几行.md)
3. [Linux 磁盘整体情况](/shell/磁盘整体情况.md)
4. [grep邮件地址正则表达式的匹配书写](https://luckywater.top/2019/04/25/Regular-Expression/)

## dataStruct

1. [B, B-, B+树的定义，特性，联系与区别（红黑树）](/dataStruct/树的联系与区别.md)
2. [图的表示和存储](/dataStruct/图的表示和存储.md)
3. [排序算法的介绍和时间复杂度] 

## OS

### Linux 中断

1. [中断的定义 和 中断处理过程的描述?](/8.1Dji大疆/OS中断处理过程的描述.md)
2. [Linux软中断, 软件中断 和硬件中断的区别](/OS/Linux中断之间区别.md)
3. [Linux中断分层和中断嵌套的概念](/OS/Linux中断分层的概念.md)
4. [进程上下文切换 VS 中断上下文切换](/OS/Linux进程上下文切换和中断上下文切换.md)

### Linux 驱动

1. [Linux总线驱动模型platform](OS/Linux驱动模型platform.md)
2. [Linux字符驱动和块驱动模型](/OS/Linux字符驱动和块驱动模型.md)

### Operate System

1. [OS内存泄漏的理解](/OS/内存泄漏的理解.md)
2. [OS中信号量, 互斥体, 自旋锁的概念](/OS/OS信号量互斥体自旋锁的概念.md)
3. [Linux kernel原理]

+ [参考链接](https://blog.csdn.net/LIJJ1993/article/details/82118483)