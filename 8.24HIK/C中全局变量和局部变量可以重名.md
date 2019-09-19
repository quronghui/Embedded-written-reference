## C中全局变量和局部变量可以重名

1. 全局变量和局部变量是可以重名的

   + 变量名相同时, 使用就近原则处理;

   ```
   int num = 123;
   
   void num_value()
   {
    	int num = 789;
    	printf("The num value is %d.\n", num);
   }
   
   int main()
   {
   	int num = 456;
   	printf("The num value is %d.\n", num);
   	return 0;
   }
   
   // The num value is 789.
   // The num value is 456.
   ```

2. static修饰的全局变量和局部变量值的计算

   ```
   //
   // Created by quronghui on 2019/9/16.
   //
   // 题目：static修饰的全局变量和局部变量值的计算
   // （1）全局变量和局部变量重名时，按照就近原则取；
   //  (2)static 修饰的变量，分为模块内和模块外
   //  (3)a++自加运算时，先返回a做运算，然后a才自加
   #include <stdio.h>
   
   static int a = 1;
   
   int f(int c)
   {
       static int a = 2;   // 考虑这个静态变量会存储值吗？ 会进行存储，知道整个程序运行完才释放；所以第二次调用时a=3；
       c = c + 1;
       return a++ + c;     // 此时先取a的值计算后，才进行a++;
   }
   
   int main()
   {
       int i, k=0;
       for (i = 0; i < 2; ++i) {
           int a = 3;  //定义了局部变量a
           k += f(a);
       }
       k += a;     // 这时候的a用的是全局变量a的值
       printf("%d\n", k);
       return 0;
   }
   // 输出值为14；
   ```
