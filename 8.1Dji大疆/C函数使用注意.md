## C 函数strcpy，memcpy，memset 的区别

### 函数的区别

1. strcpy

   + strcpy的作用是**拷贝字符串**，当它遇到'\0'时结束拷贝。

   + **注意**：存在拷贝越界的问题；

   + ```
     extern char *strcpy(char *dest,char *src);	//就是把src的字符串复制到dest中
     ```

2. **memcpy**

   + memcpy用来做**内存拷贝**，可以拿它拷贝任何数据类型的对象，可以指定拷贝的数据长度。

   + **注意**：内存重叠的问题

   + ```
     void *memcpy(void *dest, const void *src, size_t n)	 // 其中dest为返回的值
     ```

3. sprintf

   - 操作源对象可以是多种数据类型，目的操作对象是字符串 
   - 实现其他数据类型格式到字符串的转化； 

4. memset

   + memset的作用是对一段内存空间全部**设置为某个字符**，常用在内存空间的初始化。
   + 其原型为 void *memset(void *s,int c,size_t n); 就是把已开辟内存空间s的首n个字节设置为c。

   

### C库函数中，size_t类型定义的变量值

1. C中使用memcpy()系列函数时要足够小心?

   ```
   void * memcpy ( void * destination, const void * source, size_t num );
   ```

   - 注意最后一个参数是 **字节**数  == **sizeof(size_t)**

   ```
   int main() {
   	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
   	memcpy(a + 3, a, 5);		// 想实现5个int类型的数复制 ; 修改 为 memcpy(a + 3, a, 5*sizeof(int));
   	for (int i = 0; i<10; i++){
   		printf("%d ", a[i]);
   	}
   	return 0;
   }
   ```

   - 解答：0 1 2 0 1 5 6 7 8 9

### memcpy内存重叠的问题

1. dst的起始位置，和src指向的内存空间位置存在一定的关系

   ![memcpy.png](https://github.com/quronghui/Embedded-written-reference/blob/master/C/photo/memcpy.png)

2. 内存复制的时候：内存空间的增长情况

   + 属于栈空间的增长，从高地址到低地址；

3. 内存重叠的现象

   ```
   src < dst < src + num;		// 当其地址的情况是这样的时候，就出现地址重叠
   ```

4. 如何解决地址重叠的问题

   ```
   const char *q = (const char *)src ;  	//将其转化为char，一个字节一个字节的进行复制
   char *p   = (char *)dst;
   p = p + num  -  1				// 将两个指针都移动到低地址
   q = q + num - 1;
   //  实现从低地址 -- > 到高地址的移动复制
   ```

   + [实现memcpy函数和优化](https://github.com/quronghui/DataStructAndAlogrithmCode/blob/master/CompanyWrite/1_Dji/strncmp.c)

### strcpy

1. 考虑内存溢出的情况；
   + 注意给目的地址加上'\0';
2. 实现[strcpy and strcnpy](https://github.com/quronghui/DataStructAndAlogrithmCode/blob/master/c_library/my_strcpy.cpp)