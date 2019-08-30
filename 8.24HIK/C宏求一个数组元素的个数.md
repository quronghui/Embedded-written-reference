## C宏求一个数组元素的个数

1. C宏求一个数组元素的个数

   ```
   // 给一个数组名table, 求其数组中元素的个数
   #define SIZEOF(table)  sizeof(table)/(sizeof(table[0]))
   ```

   + 先求出数组table的总长度, 除以每一个元素占有的大小

