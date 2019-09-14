### echo 重定义 和 grep 正则表达式匹配

1. 重定向标准输出和标准错误 到同一文件

   ```
	$ echo hello 1>&2 | grep aaa		// 通过stderr直接输出hello，buffer里面此时为空，没有其他的值
   $ echo hello 2>&1 |grep aaa			// 无输出；buffer里面的内容hello和aaa不匹配，所以没有输出
   ```
   
   + echo hello ：将hello输出到屏幕；
   + 1>&2：将stdout重定向到stderr通道，也就是将stdout的内容通过stderr显示出来；
     + stdout ：先放在缓冲区中
     + stderr：直接输出到屏幕；
   + grep aaa：匹配这个buffer里面是否存在aaa; 
   
2. grep 正则表达式

   - 一个连行符 : 由一个斜杠字符其后紧跟一个回车符组成。它们之间不允许有空白字符。

   

