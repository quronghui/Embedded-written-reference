## CPU , Cache，MMU ，内存之间的关系？

![MMU_cache.png](/OS/photo/MMU_cache.png)

### MMU的有无

1. 带有MMU的系统：
   + linux 内核和用户程序都运行在虚拟地址模式；

2. 没有MMU的系统
   + 用户空间和内核空间是不做区分的；
   + 不能使用处理器的虚拟内存管理技术；