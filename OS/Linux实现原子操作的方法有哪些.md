## Linux实现原子操作的方法有哪些

1. 自旋锁 spin_lock
2. 信号量
3. SMP cpu 是lock指令
   + *SMP*的全称是"对称多处理"（Symmetrical Multi-Processing）技术
   + 使用总显得方式；
4. 比较特殊的可能要屏蔽中断