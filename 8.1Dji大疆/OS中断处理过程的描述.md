## 硬件中断的实现过程:

- 设备准备好进程间上下文切换的工作 —> CPU发出硬件中断 —> CPU 执行OS 中预先定义的中断服务例程ISR(interrupt server routine) / 中断处理程序(interrupt handler) —> 返回唤醒等待的I/O进程继续执行.

