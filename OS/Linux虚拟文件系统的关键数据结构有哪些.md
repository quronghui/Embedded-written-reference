

## linux[虚拟文件系统](https://www.baidu.com/s?wd=虚拟文件系统&tn=SE_PcZhidaonwhc_ngpagmjz&rsv_dl=gh_pc_zhidao)核心数主要有以下几个数据结构：

* 超级块结构(struct super_block {...} )
该结构保存了一个被安装在[linux系统](https://www.baidu.com/s?wd=linux系统&tn=SE_PcZhidaonwhc_ngpagmjz&rsv_dl=gh_pc_zhidao)上的文件系统的信息。对于基于磁盘的文件系统，该结构一般和保存在磁盘上的"文件系统控制块"对应。也就是说如果是磁盘文件系统，该结构保存的磁盘文件系统的控制信息。
* inode结构( struct inode {...} )
该结构中存储的是一个特定文件的一般信息，对于一个基于磁盘的文件系统，该结构对应磁盘上的"文件数据控制块"。每一个inode结构都对应一个inode节点号，这个节点号是唯一的，它也唯一标识一个文件系统中的文件。
* file结构( struct file {...} )
该结构中存储的是一个打开的文件和打开这个文件的进程间的交互信息。该结构保存在kernel的内存区，在打开文件时被创建，关闭文件时被释放。
* dentry结构( struct dentry {...} )
该结构存储的是目录实体和对应的文件的关联信息。

## Linux是通过什么组件来实现支持多种文件系统？

1. VFS--虚拟文件系统
   + 采用标准的Unix系统调用读写位于不同物理介质上的不同文件系统。
   + 通过VFS：一个抽象的通用访问接口屏蔽了底层文件系统和物理介质的差异性。
   + VFS是一个可以让open()、read()()、write()等系统调用不用关心底层的存储介质和文件系统类型就可以工作的粘合层。
2. 在古老的[DOS操作系统](https://www.baidu.com/s?wd=DOS操作系统&tn=SE_PcZhidaonwhc_ngpagmjz&rsv_dl=gh_pc_zhidao)中
   + 要访问本地文件系统之外的文件系统需要使用特殊的工具才能进行。