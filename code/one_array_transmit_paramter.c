//
// Created by quronghui on 2019/9/27.
//
// 题目一：一维数组的传参方式;

#include <stdio.h>
#include <string.h>

/*
 * （一）题目一：一维数组的传参方式;
 * （a）数组名退化为指针传参，代表的是数组首元素的地址
 * （b）不能通过传递的参数名，计算数组的长度；
 * （c）如果是变量的值传递，那么形参就是实参的一份拷贝
 * */
// (1)用数组的形式传递参数，不需要指定参数的大小;
// 因为在一维数组传参时，形参不会真实的创建数组,传的只是数组首元素的地址;
void test1(int arr[])
{
    printf("hello  ");
    printf("sizeof(arr)/ sizeof(int) = %ld\n", sizeof(arr)/ sizeof(int));  // 值为2；传参数之后不能计算数组长度的；
}

void test2(int arr[10])
{
    printf("world.  ");
    printf("sizeof(arr)/ sizeof(int) = %ld\n", sizeof(arr)/ sizeof(int));  // 值为2；传参数之后不能计算数组长度的,此时的arr表示首元素的首地址；

}

// (2)一维数组传参退化，用指针进行接收，传的是数组首元素的地址
void test3(int *arr)
{
    printf("pointer ");
    printf("sizeof(arr)/ sizeof(int) = %ld\n", sizeof(arr)/ sizeof(int));  // 值为2；传参数之后不能计算数组长度的,此时的arr表示首元素的首地址；
}

// (3) 传递的是指针数组，传过去的是数组名;也不能计算
void test4(int *arr[20])
{
    printf("pointer array ");
    printf("sizeof(arr)/ sizeof(int) = %ld\n", sizeof(arr)/ sizeof(int));  // 值为2，不能计算
}
// （4）传过去是指针数组的数组名，代表首元素地址，首元素是个指针向数组的指针，再取地址，就表示二级指针，用二级指针接收
void test5(int **arr)
{}


int main()
{
    int arr[10] = {0};
    int length = sizeof(arr)/ sizeof(int);
    int *arr1[20] = {0};   // 定义了一个指针数组
    test1(arr);
    test2(arr);
    test3(arr);
    test4(arr1);
}
