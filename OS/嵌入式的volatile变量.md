## 嵌入式的volatile变量

### volatile变量

1. Volatile是区分C程序员和嵌入式系统程序员最基本的问题。

   +  嵌入式系统程序员经常同硬件、中断、RTOS等打交道，所有这些都要求volatile变量
   + Volatile：作为指令关键字, 确保本条指令不会因编译器的优化而省略；
   + 寄存器中的值会被认为的改变，所以必须要求每次直接读值。

2. 实例区别

   ```
   // 对一个变量进行连续的赋值
   void main(){	
       XBYTE[2]=0x55;		
       XBYTE[2]=0x56;
       XBYTE[2]=0x57;
       XBYTE[2]=0x58;
    }
   ```

   + 不加volatile: 译器就不能像对待纯粹的程序那样对上述四条语句进行优化只认为XBYTE[2]=0x58，而忽略前三条语句，并且只产生1条机器码
   + 用volatile修饰过，此时编译器会逐一的进行编译并产生相应的4条机器码。

3. 使用volatile变量的例子

   1). 并行设备的硬件寄存器（如：状态寄存器）

   2). 一个中断服务子程序中会访问到的非自动变量(Non-automaticvariables)

   3). 多线程应用中被几个任务共享的变量

### 其他的问题

1. 一个参数既可以是const还可以是volatile吗？

   + 可以的；
   + volatile修饰：因为它可能被意想不到地改变；
   + const修饰：因为程序不应该试图去修改它

2.  一个指针可以是volatile 吗？

   + 是的
   + 例子：一个中断服务子程序修改一个指向一个buffer的指针时

   ```
   // 返回*ptr指向值的平方；但是达不到预期的效果，第二次读值的时候被改变了；
   int square(volatile int *ptr)
   {
   　　return *ptr * *ptr;	// 在这里，需要两次从内存中读取值
   }
   
   // 正确的代码：只进行一次读值
   long square(volatile int *ptr)
   {
   　　int a;
   	　a = *ptr;
   　　return a * a;
   }
   ```

   