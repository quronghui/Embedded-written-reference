## ioctl和unlock_ioctl的区别

1. 首先说明在2.6.36以后ioctl函数已经不再存在了

   + 而是用unlocked_ioctl和compat_ioctl两个函数实现以前版本的ioctl函数。
   + 区别：去除了原来ioctl中的**struct inode参数**，同时改变了返回值。

   ```
   int (*ioctl) (struct inode * node,struct file *filp, unsigned int cmd, unsigned long arg);
   ```

2. 驱动设计过程中存在的问题变化并不是很大

   + 同样在应用程序设计中我们还是采用ioctl实现访问
   + 而并不是unlocked_ioctl函数，因此我们还可以称之为ioctl函数的实现。

3. inode 参数

   + 文件的元数据

   + inode和file：ioctl的操作有可能是要修改文件的属性，或者访问硬件。要修改

     文件属性的话，就要用到这两个结构体了，所以这里传来了它们的指针。