## Linux把名称中含有test内容的进程找出来杀死

1. 先找出含有"test"的进程的pid

   ```
   $ ps	|	grep	test
   ```

2. 进程杀死

   ```
   $ kill	pid
   ```

   

