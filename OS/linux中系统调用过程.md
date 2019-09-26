## linux中系统调用过程？

### 进程的三部分：运行模式、地址空间、上下文

![process_status.png](https://github.com/quronghui/Embedded-written-reference/blob/master/OS/photo/process_status.png)

### linux中系统调用过程

1. 系统调用的作用？
   1. **控制硬件：**系统调用往往作为硬件资源和用户空间的抽象接口，比如读写文件时用到的write/read调用。
   2. **设置系统状态或读取内核数据：**因为系统调用是用户空间和内核的唯一通讯手段，所以用户设置系统状态，比如开/关某项内核服务（设置某个内核变量），或读取内核数据都必须通过系统调用。比如getpgid、getpriority、setpriority、sethostname
   3. **进程管理：**用来保证系统中进程能以多任务在虚拟内存环境下得以运行。比如 fork、clone、execve、exit等
   
2. 系统调用实现过程？
   + （1）程序调用libc库的API函数，查找到**系统调用号**；
   + （2）通过汇编指令int 0x80， 调用软中断进入内核；
   + （3）内核中首先执行system_call 函数；通过SAVE_ALL**保存**系统调用号（eax）和CPU寄存器到相应的堆栈中；
   + 接着根据系统调用号在系统调用表中查找到对应的系统调用服务例程。
   + （4）**执行该服务例程**。
   + （5）执行完毕后，转入ret_from_sys_call 例程，从**系统调用返回**
   
   ![ret_sys.png](https://github.com/quronghui/Embedded-written-reference/blob/master/OS/photo/ret_sys.png)
   
3. 系统调用的处理函数

   + 函数的名称前缀都是 sys_：标识为一个系统调用的处理程序函数
   + 所有的处理程序函数都最多接收 5 个参数。否则，用一个单独的寄存器指向进程  地址空间中这些参数值所在的一个内存区即可。
   + 所有的系统调用都在内核态执行
   + 系统调用由内核分配的一个编号唯一标识（系统调用号）

   ![sys_call.png](https://github.com/quronghui/Embedded-written-reference/blob/master/OS/photo/sys_call.png)

4. [其他例子](https://blog.csdn.net/cs2539263027/article/details/78977054)

### 举例：read的系统调用过程？

1. 举例：read的系统调用过程？

   + 例如read系统调用，0x80 中断处理程序接管执行后，先检查其系统调用号，然后根据系统调用号查找系统调用表，并从系统调用表中得到处理 read 系统调用的内核函数 sys_read ，最后传递参数并运行 sys_read 函数。
   + 至此，内核真正开始处理** read 系统调用**（sys_read 是 read 系统调用的内核入口）

   [如:应用程序中read()在linux中执行过程即从用户空间到内核空间？](https://my.oschina.net/haomcu/blog/468656)