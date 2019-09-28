//
// Created by quronghui on 2019/9/27.
//
// 题目四：指针函数和函数指针的用法

#include <stdio.h>
#include <malloc.h>

/*
 * 一.指针函数的用法：
 *  (a)接受指针函数的返回值：此时的返回值是一个指针
 * */
typedef struct _Data{
    int a;
    int b;
}Data;

// （1）定义一个指针函数
Data *f(int x, int y)
{
    Data *data = (Data *)malloc(sizeof(Data));
    data->a = x;
    data->b = y;
    return data;
}
// (2) 测试指针函数的用法
void test_pointer_function()
{
    Data *mydata = f(4,5);  // 用于接收指针函数的返回值
    printf("mydata->a = %d, mydata->b = %d\n",mydata->a,mydata->b);
}

/*
 * (二)函数指针的用法
 * (a)本质是一个指针，指向了一个函数;
 * */

// (1)构造两个功能函数
int add(int x, int y)
{
    return x+y;
}
int sub(int x, int y)
{
    return x-y;
}
// (2)定义函数指针: 可以通过typedef声明；
//typedef int (*fun)(int x, int y);
int (*fun)(int x, int y);

// （3）测试函数指针
void test_function_pointer()
{
    // 第一种赋值的写法
    fun = add;
    printf("add_(*fun)(5,3) = %d \n", (*fun)(5,3));
    // 第二种赋值的写法
    fun = &sub;
    printf("sub_(*fun)(5,3) = %d \n", (*fun)(5,3));

}

int main()
{
    test_pointer_function();
    test_function_pointer();
    return 0;
}
