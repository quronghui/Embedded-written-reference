## Linux 内核锁主要是自旋锁和信号量

### 自旋锁

```
spin_lock()				// 阻塞获取锁
spin_trylock()		//  得阻塞获取锁
spin_unlock()		//释放锁
```

### 内核信号量

1. 内核信号量和IPC信号量

   + 内核信号量：只能在内核中使用

2. 内核信号量函数

   ```
   void down();		// 获取信号量，会导致睡眠；
   void up();				// 释放sem信号量，将信号量加1；
   ```

   

![spin_lock_sem.png](https://github.com/quronghui/Embedded-written-reference/blob/master/OS/photo/spin_lock_sem.png)