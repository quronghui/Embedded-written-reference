# Embedded-written-reference
+ 2019-参加过的嵌入式笔试题目和解析分享

+ Table of Contents
  =================

     * [Embedded-written-reference](#embedded-written-reference)
        * [Contents](#contents)
        * [7.30诺瓦科技](#730诺瓦科技)
        * [8.1大疆嵌入式参考](#81大疆嵌入式参考)
        * [8.3网易笔试](#83网易笔试)

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
6. [OS简述处理器中断处理的过程](/8.1Dji大疆/OS嵌入式系统指定位反转.md)
7. [OS简述 处理器读取内存的过程](/8.1Dji大疆/OS处理器读取内存的过程.md)
8. [OS系统设计]
9. [OS 中断处理过程的描述?](/8.1Dji大疆/OS中断处理过程的描述.md)
10. [OS 如何实现进程间的切换?](/8.1Dji大疆/OS如何实现进程间的切换.md)
11. [C语言的**各种变量的存取区域**，给你一段小程序，让你分析各个变量的存储区域?](/8.1Dji大疆/C变量存储区域.md)
12. [C中使用memcpy()系列函数时要足够小心?](/8.1Dji大疆/C函数使用注意.md)
13. [C语言**编译执行**的四个阶段?](/8.1Dji大疆/C语言编译执行的四个阶段.md)
14. [C简述实时操作系统和非实时操作系统特点和区别?](/8.1Dji大疆/C的static作用.md)
15. [简述**C函数中参数**传递问题](/8.1Dji大疆/简述C函数中参数传递问题.md)
16. [linux**目录结构**，选项是/usr、/tmp、/etc目录的作用?](/8.1Dji大疆/linux目录结构.md)
17. [linux系统打开设备文件，进程可能处于三种基本状态?如果多次打开设备文件，驱动程序应该实现什么?](/8.1Dji大疆/linux系统打开设备文件处于的状态.md)
18. *未全部完成 --*[Linux内核中常用的两个宏定义?](/8.1Dji大疆/linux内核中常用的两个宏定义.md)
19. [Online Judge:  实现一个循环缓冲区.](https://github.com/quronghui/DataStructAndAlogrithmCode/blob/master/CompanyWrite/1_Dji/circularReadWrite.c)

### 8.4 大疆笔试

1.  [C : 当char类型变量进行赋值时, 超过其范围时怎么处理?](https://github.com/quronghui/DataStructAndAlogrithmCode/blob/master/CompanyWrite/1_Dji/charConvertint.c)
2. [C: 有符号的变量(负数)和无符号的变量(正数)相加](/8.1Dji大疆/C有符号的变量和无符号的变量相加.md)
3.  [C: 关键词的描述](/8.1Dji大疆/C关键词的描述.md)
4.  [C: 如何实现一个数的四舍五入?]
5.  [OS 结构体和联合体的**内存字节**对齐计算?](https://luckywater.top/2019/08/02/PragmaPack/)
6.  *未全部完成 --* [OS并发: 可以通过哪些方法进行同步?](/8.1Dji大疆/OS并发的同步机制.md)
7.  [OS 简述一个执行程序在运行时的内存布局?]( /8.1Dji大疆/OS简述一个执行程序在运行时的内存布局.md)
8.  [OS简述线程之间的同步互斥时占用空间的大小]( /8.1Dji大疆/OS简述线程之间的同步互斥时占用空间的大小.md)
9.  [Online Judge :  忽略字母大小写的差异, 实现字符串比较? ](https://github.com/quronghui/DataStructAndAlogrithmCode/blob/master/CompanyWrite/1_Dji/strncmp.c)

### 8.15 大疆初面

1. 自我介绍和项目的描述?
2. [OS cache缓存一致性描述?](/8.1Dji大疆/OScache缓存一致性描述.md)
3. [OS cache多任务调度描述?](/8.1Dji大疆/OScache多任务调度描述.md)
4. [Linux 多任务, 进程, 线程之间的关系?](/8.1Dji大疆/Linux多任务, 进程, 线程之间的关系.md)
5. [Linux查询进程和线程数量?](/8.1Dji大疆/Linux查询进程和线程数量.md)
6. *未全部完成 --[嵌入式实时操作系统描述?](/8.1Dji大疆/OS嵌入式实时操作系统描述.md)
7. 做过一些驱动开发吗?
   + [参考](https://www.jianshu.com/p/716ed9cdb8f3)

## 8.3网易笔试

1. [Linux 系统权限755 777 644 ?](/8.3网易/LInux系统权限.md)
2. 没做出来 -- [echo 重定义 和 grep 正则表达式匹配](/8.3网易/echo 重定义 和 grep 正则表达式匹配.md)
3. [Dijkstra最短路径算法的描述正确的是?](/8.3网易/Dijkstra最短路径算法的描述.md)
4. [TCP IP 数据传输中, 数据如何进行分包?](/8.3网易/TCPIP数据分包.md)
5. [二叉树8个度为2节点, 5个度为1节点 , 度为0有多少个节点?](/8.3网易/二叉树节点和度.md)