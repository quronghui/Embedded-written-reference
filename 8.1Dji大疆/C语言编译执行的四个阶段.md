### C函数使用注意

1. C语言**编译链接**的四个阶段？

   ![Cobject_link.png](/8.1Dji大疆/photo/Cobject_link.png)

   1. 预编译:
      - "#" 相关的语句: 进行展开;
      - 例如: #define : 宏定义展开
   2. 编译: 翻译
      - 分析代码的语法和语义, 将**变量和关键字** **翻译**成中间代码或者汇编代码;
   3. 汇编: 翻译
      - 将汇编语言**翻译**为机器可识别的二进制代码
      - .o 是二进制文件
   4. 链接: 
      - 将目标文件所需的**库, 文件**进行链接

2. [程序编译成可执行文件的代码](https://luckywater.top/2019/03/18/ComplationAndC/)

   + ```
     $ gcc -S main.c -o main.s	//生成汇编代码
     $ gcc -c main.s -o main.o	//生成目标文件 
     $ gcc main.o -o main		//生成可执行文件
     ```

3. volatile应该是在**编译阶段**，extern在**链接阶段**。

   + volatile：告诉编译器，修饰的变量不能优化，每次读取需要从内存中读取；

