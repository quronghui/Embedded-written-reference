## 四大CPU体系结构

### RISC (reduced instruction set computer)

1. 精简指令集计算机性能
   + 性能特点一：由于指令集**简化**后，流水线以及常用指令均可用硬件执行； 
   + 性能特点二：采用大量的寄存器，使大部分指令操作都在寄存器之间进行，提高了处理速度； 
   + 性能特点三：采用**缓存—主机—外存**三级存储结构，**使取数与存数**指令分开执行，使处理器可以完成尽可能多的工作，且不因从存储器存取信息而放慢处理速度。

### ARM系列

1. 是一个32位精简指令集（RISC）处理器架构，其广泛地使用在许多嵌入式系统设计

### **x86系列/Atom处理器**

1. 英特尔Intel首先开发制造的一种微处理器体系结构的泛称。
2. x86架构是重要地可变指令长度的CISC（复杂指令集电脑）

### **MIPS系列**

1. MIPS是世界上很流行的一种RISC处理器。MIPS的意思是“无内部互锁流水级的微处理器”(Microprocessor without interlocked piped stages)
2. 机制是尽量利用软件办法避免流水线中的数据相关问题

### **PowerPC系列**

1. PowerPC 是一种精简指令集（RISC）架构的中央处理器（CPU）
2. 基本的设计源自IBM（国际商用机器公司）的IBM PowerPC 601 微处理器POWER

### **互补型的实时性(Real Time)较好的DSP架构**

1. DSP是微处理器的一种,这种微处理器具有极高的处理速度.因为应用这类处理器的场合要求具有很高的实时性(Real Time)。

## MIPS cpu地址空间划分

1. 2G的用户空间，2G内核空间

   ![mips_cpu.png](https://github.com/quronghui/Embedded-written-reference/blob/master/OS/photo/mips_cpu.png)

2. 具体地址空间内容

   ![mips_kseg.png](https://github.com/quronghui/Embedded-written-reference/blob/master/OS/photo/mips_kseg.png)

