## TCP和UDP的区别

| 区别             | TCP                                            | UDP                                                          |
| ---------------- | ---------------------------------------------- | ------------------------------------------------------------ |
| 数据包分割与重组 | TCP层完成分割，目的主机TCP重组                 | 源路由器数据分割，目的主机重组                               |
| 连接             | 三次握手，四次挥手                             | 不建立连接                                                   |
| 数据单位         | 段（面向字节流）                               | 数据报                                                       |
| 丢包重试         | 丢包重发控制，顺序控制，超时重传，窗口流量控制 | 不会进行丢包重试，也不会纠正到达的顺序                       |
| 对应关系         | 一对一                                         | 支持一对一，一对多，多对一和多对多的交互通信                 |
| 头部开销         | 最小20字节                                     | 只有8字节                                                    |
| 拥塞控制         | 有控制                                         | 有拥塞控制，因此网络出现拥塞不会使源主机的发送速率降低（对实时应用很有用，如IP电话，实时视频会议等） |

### [TCP的三次握手](https://blog.csdn.net/weixin_34391445/article/details/88022343)

1. TCP 的通过三次握手建立连接
   1. client : 发送SYN( syn_j = j )请求包给server; 并进入SYN_SEND状态,等待服务器确认;
   2. server: 收到请求并确认 , 发送ACK(ack = syn_j+1); 同时server发送一个SYN(syn_k = k); 并进入**SYN_RECV**状态;
      - 同时发送SYN+ACK 请求
   3. client: 收到SYN+ACK包, 向server发送ACK(ack = syn_k + 1); 
   4. client 和 server 同时进入**established**状态;
2. TCP为什么需要第三次握手?
   - 防止服务器端的一直等待而浪费资源。防止接收方收不到信息而已，发送方也不知道接收方收到还是没收到
   - 如果没有三次握手，那么服务器发送确认后，连接就建立了，而此时客户端没有发送建立连接的请求报文段，于是不理会服务器的确认，也不会给服务器发送数据，而服务器却一直等待客户端发送数据，因此服务器的许多资源就浪费了，采用三次握手的方式就可以防止这种事情发生。

### TCP四次挥手

1. TCP第4次挥手为何要等待2MSL才关闭？

   - MSL(Maximum Segment Lifetime)报文最大生存时间

     - 任何报文在网络上存活的最大时间，一旦超过该时间，报文就会被丢弃。
     - **TIME_WAIT = 2MSL**也就是指的2倍MSL的时间。

   - 保证客户端最后一次挥手的报文能够到达服务器，若第4次挥手的报文段丢失了，服务器就会超时重传第3次挥手的报文段, client是保持**TIME_WAIT**

     ![TCP_MSL.png](https://github.com/quronghui/Embedded-written-reference/blob/master/TCP/photo/TCP_MSL.png)

### TCP 的窗口控制和重发控制

![tcp_flow.png](https://github.com/quronghui/Embedded-written-reference/blob/master/TCP/photo/tcp_flow.png)

### TCP的分包机制

1. TCP/ IP 数据传输中, 数据如何进行分包?
   - 按照最大的传输单元MTU进行计算;
   - 注意数据包需要包含首部