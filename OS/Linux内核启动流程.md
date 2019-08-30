## Linux内核启动流程

1. 内核先执行一个文件head-armv.S

   ```
   arch/arm/kernel/head-armv.S 
   ```

   + 该文件是内核最先执行的一个文件：
     + 包括内核入口**ENTRY(stext)**
     + 到**start_kernel**间的初始化代码
   + 作用： 检查CPU ID， Architecture Type，初始化BSS等操作，并跳到start_kernel函数

2. 在执行这个文件前，处理器应该处于这个状态

   ```
   r0 - should be 0 			// 寄存器关闭
   r1 - unique architecture number 
   MMU - off 
   I-cache - on or off 
   D-cache – off 
   ```

### ENTRY(stext)启动源码分析

```
/* 部分源代码分析 */ 
 /* 内核入口点 */ 
ENTRY(stext) 
/* 程序状态，禁止FIQ、IRQ，设定SVC模式 */ 
 mov r0, #F_BIT | I_BIT | MODE_SVC@ make sure svc mode 
 /* 置当前程序状态寄存器 */ 
 msr cpsr_c, r0 @ and all irqs disabled 
 /* 判断CPU类型，查找运行的CPU ID值与Linux编译支持的ID值是否支持 */ 
 bl __lookup_processor_type 
 /* 跳到__error */ 
 teq r10, #0 @ invalid processor? 
 moveq r0, #'p' @ yes, error 'p' 
 beq __error 
 /* 判断体系类型，查看R1寄存器的Architecture Type值是否支持 */ 
 bl __lookup_architecture_type 
 /* 不支持，跳到出错 */ 
 teq r7, #0 @ invalid architecture? 
 moveq r0, #'a' @ yes, error 'a' 
 beq __error 
/* 创建核心页表 */ 
 bl __create_page_tables 
 adr lr, __ret @ return address 
 add pc, r10, #12 @ initialise processor 
 /* 跳转到start_kernel函数 */ 
 b start_kernel 
```

### [start_kernel()源码详解](https://www.linuxidc.com/Linux/2014-10/108034.htm)