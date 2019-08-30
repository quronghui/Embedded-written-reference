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

   