## copy_to_user 、copy_from_user函数

| 区别                 | copy_to_user()                                               | copy_from_user()                                            |
| -------------------- | ------------------------------------------------------------ | ----------------------------------------------------------- |
| **系统调用**中的函数 | 将**内核空间**的数据复制到 --> 用户空间                      | 将**用户空间**的数据复制到 -->内核空间                      |
| 返回值               | 成功返回0<br />失败返回没有拷贝成功的数据**字节数**          | 同左                                                        |
|                      | access_ok(); 检测用户空间缓存区的合法性, 才能进行读写;       |                                                             |
|                      |                                                              |                                                             |
| **内核**中的函数     | put_user(data, ptr)                                          | get_user(data, ptr)                                         |
| 作用                 | 将**内核空间**的变量data中的数值，保存到到用户空间指定的ptr处 | 获取**用户空间**指定地址ptr中的数值，并保存到内核变量data中 |
| 返回值               | 成功返回0，不成功返回非0                                     |                                                             |

### 函数详解

1. copy_from_user()

   ```
   unsigned long copy_from_user(void *to, const void *from, unsigned long n);
   // to: 目标地址 -- 内核空间
   // from: 源地址 -- 用户空间
   // n:就是拷贝的字节数
   ```

   + 将用户空间中的n个数据拷贝到内核空间；
   + 成功返回0，失败返回没有拷贝成功的数据**字节数**

2. get_user宏

   ```
   int get_user(data, ptr);
   // data: 可以是字节、半字、字、双字类型的内核变量
   // ptr：用户空间的内存指针；
   ```

   + 成功返回0，失败返回非0
   + 获取用户空间指定地址ptr中的数值，并保存到内核变量data中

3. copy_to_user()

   ```
   unsigned long copy_to_user(void *to, const void *from, unsigned long n)
   // to：目标地址 -- 用户空间
   // from：源地址 -- 内核空间
   // n：就是拷贝的字节数
   ```

   + 将内核空间中的n个数据拷贝到用户空间；
   + 成功返回0，失败返回没有拷贝成功的数据字节数

4. put_user宏：

   ```
   int put_user(data, prt）
   // data: 可以是字节、半字、字、双字类型的内核变量
   // ptr：用户空间的内存指针；
   ```

   + 成功返回0，失败返回非0
   + 将内核空间的变量data中的数值，保存到到用户空间指定的ptr处。

### copy_from_user() 函数和memcpy()的区别

1. 崩溃影响？

   + 用户空间的进程崩溃：不会影响系统的其它进程；
   + 系统内核崩溃：就什么都结束了

2. memcpy

   ```
    void *memcpy(void *dest, const void *src, size_t n);
   ```

3. copy_from_user()

   + access_ok(); 检测用户空间缓存区的合法性, 才能进行读写;
   + 如果直接用memcpy操作，进入缺页异常处理，因为无法进行修复，导致**内核崩溃**