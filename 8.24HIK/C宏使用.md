## C宏使用

1. 实现对一个变量的bit2置位操作

   ```
   // bit2, 就是变量的第二位
   #define  SEETING(a)  (a&( ~(0x01<<2))
   or #define  SEETING(a)  (a&( ~2)
   
   ```

   

