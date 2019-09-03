## linux中netfilter的实现机制？

1. Linux netfilter就是借助一整套的 hook 函数的管理机制，实现数据包在三层以上的过滤、地址转换(SNAT、DNAT)、基于协议的连接跟踪。

   + 我们所说的内核的netfilter，应该包括二层数据的filter操作，以及对三层及三层以上数据的filter等操作。

2. 只不过二层的filter实现与三层及三层也上的filter实现有所不同

   + 其中二层的filter与应用层程序ebtables结合使用，
   + 而三层及以上的filter结合iptables使用。
   + 但是二层filter与三层filter使用的都是统一的hook机制。

3. linux抽象出整体的hook架构，通过在以下几个数据流经点添加hook机制

   + NF_IP_PRE_ROUTING、NF_IP_LOCAL_IN、NF_IP_FORWARD、NF_IP_LOCAL_OUT、NF_IP_POST_ROUTING

   ![linux_hook.png](https://github.com/quronghui/Embedded-written-reference/blob/master/OS/photo/linux_hook.png)

