### OS系统中的位运算

1. OS多任务嵌入式系统中，有一个CPU可直接寻址的32位寄存器REGn，地址为0x1F000010，编写一个安全的函数，将寄存器REGn的指定位反转（要求保持其他bit的值不变)

   ```
   void bit_reverse(uint32_t nbit)
   {
       *((volatile unsigned int *)0x1F000010) ^= (0x01 << nbit);
   }
   ```

2. OS系统中的位运算

   + 特定位清零用  &
   + 特定位置1用     |
   + 特定位取反用  ^

