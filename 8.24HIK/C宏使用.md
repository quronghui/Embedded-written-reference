## #define 的作用

### 实现一个变量的置位操作

1. 实现对一个变量的bit2置位操作

   ```
   // bit2, 就是变量的第二位
   #define  SEETING(a)  (a&( ~(0x01<<2))
   or 
   #define  SEETING(a)  (a&( ~2)
   ```

### 求一个数组元素的个数

```
// 给一个数组名table, 求其数组中元素的个数
#define SIZEOF(table)  sizeof(table)/(sizeof(table[0]))
```

+ 先求出数组table的总长度, 除以每一个元素占有的大小

### 用以表明1年中有多少秒（忽略闰年问题）

```
 #define SECONDS_PER_YEAR (60 * 60 * 24 * 365)UL 	// UL 表示的是长整形的变量
```

+ 意识到这个表达式将使一个16位机的整型数溢出-因此要用到长整型符号L,告诉编译器这个常数是的长整型数。 
+ 如果你在你的表达式中用到UL（表示无符号长整型）

### 输入两个参数并返回较小的一个

```
#define  MIN(a,b)  ( (a) <=  (b) ? (a) : (b) )		//学会打括号
```

1. define 定义最小值的使用中要注意一个问题

   ```
   MIN(*p++, b)
   ((*p++) <= (b) ? (*p++) : (b)) 		// 产生一个副作用，使得p自加两次
   ```

   

## typedef 的作用

1. typedef的作用

   + 用来声明一个别名，typedef后面的语法，是一个声明
   + 后面的是一个整体，而不是分开的？

   ```
   typedef int PARA ;		//  这种形式跟#define int PARA几乎一样，造成了一种误解，误以为两者是分开的；
   ```

2. 真正的理解typedef

   ```
   typedef int PARA ;	 // 将 int PARA看成一个整体，类似于 int i;
   ```

   + 声明一样是一个**整体声明**，只不过int i定义了一个变量;
   + 而typedef定义了一个**别名**

3. typedef的两个例子

   + ```
     typedef int a[10];   	// 把a声明为具有10个int元素的数组的类型别名
     typedef void (*p)(void);  		// p是一种函数指针的类型别名
     ```

4. typedef 函数指针的声明和调用

   ```
   typedef void (*convert)() ;  // typedef定义了一个函数指针；
   
   void func(void)
   {
       printf("hello.\n");
   }
   
   int main()
   {
       puts("By typedef: ");
       convert func_pp = func;		// 函数指针的指向
       (func_pp)();							// 函数指针的调用；
   }
   ```

   