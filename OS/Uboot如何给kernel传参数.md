## ARM下U-boot给Kernel传参数

1. U-boot 引导程序，在启动的时候会给Linux Kernel传递很多参数

   + 串口波特率，RAM Size，videofb、MAC Address等
   + 设备树的入口地址 

2. u-boot如何进行传递的？

   + U-boot把要传递给kernel的东西：保存在struct tag数据结构中
   + 启动kernel时，把这个结构体的物理地址传给kernel；

3. kernel解析传递的参数？

   + Linux kernel通过这个地址，用parse_tags分析出传递过来的参数

4. ARM架构上，u-boot向Linux内核传递参数利用了R0，R1和R2三个寄存器

   | 寄存器 | 作用                                                         |
   | ------ | ------------------------------------------------------------ |
   | R0     | 暂时不用，缺省放0                                            |
   | R1     | 机器号，标识计算机系统的型号，<br />内核支持的所有使用**ARM处理器的设备ID号**定义在arch/arm/tools/mach-types文件中，<br />编译内核过程中会被转换为一个头文件include/asm-arm/mach-types.h供其他文件包含使用。 |
   | R2     | R2寄存器传递的是一个地址，也就是指针的概念，这个指针指向一个**TAG区域**．<br />UBOOT和Linux内核之间正是通过这个扩展了的TAG区域来进行复杂参数的传递，<br />如 command line，文件系统信息等等，用户也可以扩展这个TAG来进行更多参数的传递。 |

   