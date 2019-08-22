## Http 和 TCP之间的区别和联系

1. TCP是底层通讯协议，定义的是数据传输和连接方式的规范
2. HTTP协议中的数据是利用TCP协议传输的，所以支持HTTP也就一定支持TCP      

### TCP 的通过三次握手建立连接

1. client : 发送SYN( syn_j = j )请求包给server; 并进入SYN_SEND状态,等待服务器确认;
2. server: 收到请求并确认 , 发送ACK(ack = syn_j+1); 同时server发送一个SYN(syn_k = k); 并进入SYN_RECV状态;
   + 同时发送SYN+ACK 请求
3. client: 收到SYN+ACK包, 向server发送ACK(ack = syn_k + 1); 
4. client 和 server 同时进入established状态;

### TCP 的通过四次挥手断开连接

1. TCP连接建立之后, 在通信双方请求关闭前, TCP连接是一直**保持不断开**(需要人为释放)
2. 四次挥手的原因 (server ACK 和FIN 是分开发的)
   + server 在发送ACK确认时, 会有一些消息传递给client;
   + server传递完ACK后, 才向client发送FIN断开请求包;

### HTTP 连接

1.  HTTP协议即超文本传送协议(Hypertext Transfer Protocol )
   + 是Web联网的基础，也是手机联网常用的协议之一
   + HTTP协议是建立在**TCP协议**之上的一种应用
2. HTTP特点
   + 客户端发送的每次请求都需要服务器回送响应，在请求结束后，会**主动释放连接**
   + 从建立连接到关闭连接的过程称为“一次连接”
