# Bootloader和BIOS、uboot和grub和bootmgr的区别

| 区别     | BIOS                                 | Bootloader                          | U-boot             | Grub               | Bootmgr   |
| -------- | ------------------------------------ | ----------------------------------- | ------------------ | ------------------ | --------- |
| 作用     | 初始化硬件，<br />不能引导OS内核     | 引导内核程序运行                    | **通用Bootloader** | 引导不同的内核启动 | 同grub    |
| 程序位置 | ROM芯片上的程序                      | RAM空间                             |                    | RAM空间            | RAM空间   |
| 程序运行 | 计算机的开启时<br />运行的第一个程序 | **内核运行前的程序**                |                    | **选择**不同的内核 | **选择**  |
|          |                                      | Bootloader =<br />BIOS+Grub/Bootmgr |                    | 支持多操作系统     | windows下 |

+ BIOS ：初始化硬件
+ Bootloader：引导内核程序的运行；
  + Grub / Bootmgr  在不同的平台下选择不同的内核运行

## BIOS

1. BIOS（Basic Input Output System）：基本输入输出系统;
   + 它是一组固化到计算机内主板上一个**ROM芯片上的程序** ，**保存着计算机最重要的基本输入输出的程序、开机后自检程序和系统自启动程序**，它可从CMOS中读写系统设置的具体信息。
   + BIOS是连接软件与硬件的一座“桥梁”，是**计算机的开启时运行的第一个程序**，主要功能是为计算机提供最底层的、最直接的**硬件设置和控制**。

### BIOS 的三个功能

1. **自检及初始化程序**，分为三个部分。
   + 加电自检（POST）：功能是检查计算机**硬件是否良好**，自检中如发现有错误，将按两种情况处理：对于严重故障（致命性故障）则**停机**，此时由于各种初始化操作还没完成，不能给出任何提示或信号；对于非严重故障则给出提示或声音**报警信号**，等待用户处理。
   + 初始化：创建中断向量、设置寄存器、对一些外部设备进行初始化和检测等，其中很重要的一部分是BIOS设置，主要是对**硬件设置的一些参数**，当计算机启动时会读取这些参数，并和实际硬件设置进行比较，如果不符合，会影响系统的启动。
   + 加载引导程序：功能是引导Dos或其他操作系统，此时会在硬盘读取引导记录，然后把计算机的控制权转交给引导记录，由**引导记录**（IPL与SPL）把操作系统装入电脑，在电脑启动成功后，BIOS的这部分任务就完成了。**也就是说BIOS本身不能引导OS内核。**
2. **程序服务处理**
   + BIOS直接与计算机的I/O设备（Input/Output，即输入/输出设备）打交道，
   + 通过特定的数据端口发出命令，传送或者接受各种外部设备的数据，实现**软件程序对硬件的直接操作**。
3. **硬件中断处理**；开机时BIOS会告诉CPU各硬件设备的中断号，当用户发出使用某个设备的指令后，CPU就根据中断号使用相对应的硬件完成工作，再根据中断号跳回原来的工作。

### 两种BIOS

```
BIOS分为：Legacy BIOS 和 UEFI BIOS
```

## Bootloader

1. Bootloader：引导加载程序（bootloader）完成比BIOS更多的功能
   + 嵌入式系统中：**Bootloader运行之后，操作系统内核才运行**；
   + 可以分为单阶段的BootLoader和多阶段的BootLoader，一般从从**固态存储**设备上启动的Bootloader大多都是 2 阶段的启动过程
   + 如uboot是2阶段的，grub就是单阶段的；

### Bootloader两个阶段功能

1. Bootloader第一阶段的功能

   + 硬件设备初始化。
   + 为加载Bootloader的第二阶段代码准备RAM空间。
   + 拷贝Bootloader的第二阶段代码到 RAM 空间中。
   + 设置好栈。
   + **跳转**到第二阶段代码的C入口点。
   + 在第一阶段进行的硬件初始化一般包括：关闭WATCHDOG、关中断、设置CPU的速度和时钟频率、RAM初始化等。

2. Bootloader第二阶段的功能

   + 初始化本阶段要使用到的硬件设备
   + 检测系统内存映射(memory map)
   + 将内核映像和根文件系统映像从Flash上读到RAM空间中。

   + **为内核设置启动参数**。
   + **调用内核**。

## 不同平台的引导加载程序

### PC平台的Grub与 bootmgr

1. GNU GRUB（GRand Unified Bootloader简称“GRUB”）
   + 是一个来自GNU项目的多操作系统启动程序。
   + GRUB是多启动规范的实现：它允许用户可以在计算机内同时**拥有多个操作系统**，并在计算机启动时**选择运行的操作系统**
   + GRUB可用于选择操作系统分区上的不同内核，也可用于向这些内核传递启动参数
     + 可用来用来引导不同系统，如windows，linux，通常用于linux，毕竟是GNU的嘛
2. Windows也有类似的工具NTLOADER、Bootmgr

### 嵌入式平台

1. U-Boot，全称为Universal Boot Loader，即通用Bootloader
2. 改名为U-Boot。
   - 支持多种嵌入式操作系统内核，如Linux、NetBSD、VxWorks、QNX、RTEMS、ARTOS、LynxOS；
   - 支持多个处理器系列，如PowerPC、ARM、x86、MIPS、XScale；