## Oops

1. 当内核出现类似于用户空间的Segmentation Fault时，Oops会被打印到控制台和写入内核log缓冲区；

   ```
   cat		/dev/globalmem		// 读取设备中节点的段错误信息
   ```

2. 如何处理Oops?

   + 栈回溯信息

     ```
     $ backtrace;		// 在gdb调试的时候，使用的方法；显示出错指令附近的机器码；
     ```

   + 使用valgrind命令

     ```
     // 编译:  gcc  -Wall -g valgrind_demo.c -o valgrind_demo
     //  执行条件 : valgrind --tool=memcheck --leak-check=full ./valgrind_demo
     // 将错误写进日志: valgrind --tool=memcheck --leak-check=full --log-file=mem_leak.log ./valgrind_demo
     // 和gdb一起调试: valgrind --tool=memcheck --leak-check=full --log-file=mem_leak.log gdb valgrind_demo
     ```

3. **[分析 Oops 信息](https://blog.csdn.net/kangear/article/details/8217329)**

   + 明确出错原因：可知内核是因为非法地址访问出错,使用了空指针。
   + 根据栈回溯信息找出函数调用关系。
   + 根据 pc 寄存器的值确定出错位置。
   + 结合内核源代码和反汇编代码定位问题。

## kernel panic

1. Panic 的等级大于 Oops

   + Oops英文单词的中文含义是“哎呀”，表示“惊叹”；

   + Panic英文单词的中文含义是“惊慌”。

2. kernel panic

   + 内核panic后，就死机了，俗称内核崩溃；
   + 内核报oops，这个时候不见得会panic，它可能只是报个oops，杀死进程而已

### 什么原因导致的kernel panic

1.  内核堆栈溢出，或者指针异常访问时，会出现kernel panic。
   +   堆栈溢出：程序循环或者多层嵌套的深度过多时，可能会导致栈溢出。
2. Linux在中断处理程序中，它不处于任何一个进程上下文，如果使用可能**睡眠的函数**，则系统调度会被破坏，导致kernel panic
   + 在中断处理程序中，是不能使用有可能导致睡眠的函数(例如信号量等)