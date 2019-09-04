## linux内核版本号查询

```
$	cat		/proc/version			// 通过proc虚拟文件系统，查询内核中的信息
```

```
  Linux version 5.0.0-25-generic (buildd@lcy01-amd64-014) 
  (gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1))
```

## 查询编译器的版本号

```
$	gcc -v;

Thread model: posix
gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1) 
```

