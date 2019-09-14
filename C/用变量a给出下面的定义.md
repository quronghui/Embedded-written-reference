##　用变量a给出下面的定义

## 题目

+ a) 一个整型数（An integer） 
+ b) 一个指向整型数的指针（A pointer to an integer）
+ c) 一个指向指针的的指针，它指向的指针是指向一个整型数（A pointer to a pointer to an integer） 
+ d) 一个有10个整型数的数组（An array of 10 integers）
+ e) 一个有10个指针的数组，该指针是指向一个整型数的（An array of 10 pointers to integers） 
+ f) 一个指向有10个整型数数组的指针（A pointer to an array of 10 integers
+ g) 一个指向函数的指针，该函数有一个整型参数并返回一个整型数（A pointer to a function that takes an integer as an argument and returns an integer） 
+ h) 一个有10个指针的数组，该指针指向一个函数，该函数有一个整型参数并返回一个整型数（ An array of ten pointers to functions that take an integer argument and return an integer ）

## 代码

```
a) 	int 	a;
b)	int		*a;
c)	int		**a;
d)	int		a[10];
e)	int		*a[10];		// 后缀的优先级[ ]  > 指针的优先级*
f)	int		(*a)[10];
g)	int		(*a)(int);
h)	int		(*a[10])(int);
```

