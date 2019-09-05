## 查询进程和线程的方法

### 查询线程方式

```
$	pstree	-p	pid		|  wc -l		//  通过wc将数量统计
$	cat		/proc/pid/status		// 通过proc虚拟文件系统

$ ulimit -s		// 查询线程的最大值
```

### 查询进程数量

```
$ ps	-m		// 查询进程的数量
$ top -H	//	动态显示进程状态；
```

1. 查询进程的最大值

   ```
   $ ulimit -a		// 查询进程的相关限制信息
   $ cat /proc/sys/kernel/pid_max; 	// PID的最大值默认设置位32768(short int 短整型的最大值)。
   $ ulimit -u 65535;					// ulimit 修改Linux的限制, 将进程扩大为int
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

## Linux把名称中含有test内容的进程找出来杀死

```
$ ps	|	grep	test		// 先找出含有"test"的进程的pid
$ kill	pid							// 杀死线程
```

## 僵尸进程查询

```
$ ps u	// 查看进程状态
STAT 为z时 -- 僵尸进程的状态
```

