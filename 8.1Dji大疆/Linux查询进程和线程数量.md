## 查询进程和线程的方法

### 查询command

```
$ ps		// 查询进程的pid, process identification value
$ cat /proc/pid/status		// 查询对应pid 的线程数量
```

1. 查询进程的最大值

   ```
   $ ulimit -a		// 查询进程的相关限制信息
   $ cat /proc/sys/kernel/pid_max; 	// PID的最大值默认设置位32768(short int 短整型的最大值)。
   $ ulimit -u 65535;					// ulimit 修改Linux的限制, 将进程扩大为int
   ```

2. 查询线程的最大值

   ```
   $ ulimit -s		// 查询线程的最大值
   ```

### 进程的创建

1. 进程的创建: fork()
   - fork() 创建成功
     - 子进程的pid, 返回给父进程;
     - 0 返回个子进程
   - fork() 创建失败
     - -1 返回给父进程; 子进程没哟返回值
2. 进程的执行和等待
   - exec() and wait()