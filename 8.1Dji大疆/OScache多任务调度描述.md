## Cache多任务调度

1. 为什么会发生页面替换问题?
   + Cache 本质是一个物理内存, 为了保证快速性所以空间有限; 淘汰掉一个不常用的页面，以便腾出主存空间来存放 新调入的页面
   + 提高TLB命中率
2. 页面替换算法
   + 随机算法，即RAND算法（Random algorithm）
   + FIFO算法（First-In First-Out algorithm）
     + 没有反映程序的局部性, 经常要使用的页面可能就在队头;
   + LFU算法（Least Frequently Used algorithm）
     + 因为到目前为止最少使用的页面，很可能也是将来最少访问的页面。
     + 实现: 为每个页面设置一个很长的定时计数器, 替换时找出**计数器最大**使用的页面;
   + **LRU算法**（Least Recently Used algorithm）
     + 近期最久没有被访问过的页面作为被替换的页面
     + 它把LFU算法中要记录数量上的"多"与"少"简化成判断"有"与"无"
   + OPT算法（OPTimal replacement algorithm）
     + 好的算法应该是选择将来最久不被访问的页面作为被替换的页面;
     + 不容易实现