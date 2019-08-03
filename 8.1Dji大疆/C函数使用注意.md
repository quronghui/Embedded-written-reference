### C函数使用注意

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