## [Linux内核中常用的两个宏定义](https://blog.csdn.net/feiyanaffection/article/details/79282562)

1. 内存中如何求一个变量的地址?

   + physical adress = virtual adress + base	(基质/界限)

2. 描述**Linux内核结构体**container_of的宏定义

   ```
   #define offsetof(TYPE,MEMBER)	((size_t)&((TYPE*)0)->MEMBER)
   #define XXX(ptr,type,member)({\
       const typeof(((type*)0)->member)	*__mptr=(ptr);\
       (type*)((char*)	__mptr 	– 	offsetof(type,member));})
   ```

### 第一个宏：offsetof

1. offsetof: 用于计算 TYPE 结构体中 MEMBER 成员的**偏移位置**

   ```
   #ifndef offsetof
   #define offsetof(TYPE, MEMBER) ((size_t)&((TYPE*)0)->MEMBER)
   #endif
   ```

2. 编译器到底做了什么?

   + `size_t`类型就是`long unsigned int`类型，这句代码的意思不就是C语言里面的强制类型转换形式
   + (TYPE*)0：将0强转为TYPE类型的指针，且指向了0地址空间；
   + (TYPE*)0->MEMEBER：指向结构体中的成员；
   + &((TYPE*)0->MEMBER)：获取成员在结构体的位置，因为起始为0，所以获取的地址即为实际的**偏移地址**。

3. 直接使用**0**地址处的值不会导致程序崩溃吗？

   + 其实上面的宏，并没有使用**0**地址处的值，而是和将 **结构体地址 和 成员变量的偏移量地址 做了加法运算**，得到成员变量的偏移位置，具体转换在代码中已经注释了。

###  第二个宏：typeof

1. typeof: 用于得到结构体的**首地址**

   ```
   #define XXX(ptr,type,member)({\
       const typeof(((type*)0)->member) *__mptr=(ptr);\
       (type*)((char*)__mptr – offsetof(type,member));})
   ```

2. 实现思路

   + typeof构造的主要应用是用在宏定义中。可以使用typeof关键字来引用宏参数的类型。也就是说，typeof(((type*)0)->member)是引用与type结构体的member成员的数据类型；
   + 获得了数据类型之后，定义一个与type结构体的member成员相同的类型的指针变量__mptr，且将ptr值赋给它；
   + 用宏offsetof(type,member),获取member成员在type结构中的偏移量；

   + 最后将__mptr值减去这个偏移量，就得到这个结构变量的地址了（亦指针）。

3. 具体的功能就是：

   + ptr是指向正被使用的某类型变量指针；
   + type是包含ptr指向的变量类型的结构类型；
   + member是type结构体中的成员，类型与ptr指向的变量类型一样。
   + **功能** : 计算返回包含ptr指向的变量所在的type类型结构变量的指针。