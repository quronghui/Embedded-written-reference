//
// Created by quronghui on 2019/9/27.
//
// 题目三：函数指针，函数指针数组，函数指针数组的指针
/*
 * (a)函数指针的形式：类型(*)()，例如：int (*p)( ).它可以存放函数的地址
 * (b)函数指针数组的定义
 * (c)函数指针数组的指针的定义
 * */

#include <stdio.h>

// （1）函数指针
typedef void (*pfun)();
void test()
{
    printf("hello,world.\n");
}

//(2)函数指针数组的定义
// parray是一个数组，每一个数组元素是一个void (*)()类型的函数指针; 函数指针数组在转换表中应用广泛?
//typedef void (*parray[10])();

// （3）函数指针数组的指针
//typedef void ((*pointer)[10])();

int main()
{
    //(1)函数指针的定义和调用
    pfun fun = test;
    fun();

    //(2)函数指针数组的定义
    void (*parray[10])();
    parray[0] = test;
    // 指向函数指针数组parray的指针pparray
    void (*(*pparray)[10])() = &parray;

    return 0;
}