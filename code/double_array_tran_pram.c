//
// Created by quronghui on 2019/9/27.
//
// 题目二：二维数组名的传参方式

/*
 *（a）二维数组的传参：至少得包含列的个数，可以不包含行的个数
 * (b) 二维数组可以使用：数组指针进行传参；本质是一个指针
 * */

#include <stdio.h>

// （1）传递二维数组的大小；
void test1(int arr[3][5])
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%d ", arr[i][j]);
        }
    }
}

// (2) 二维数组按照一维数组存储，需要知道列
void test2(int arr[][5])
{
}

// (3)通过数组指针进行传递:传过去的是二维数组的数组名，即数组首元素的地址
// 也就是第一行的地址，第一行也是个数组，用一个数组指针接收
void test6(int (*arr)[5])
{
}

// (3)不正确的传参方式
//void test3(int arr[][])
// void test4(int *arr)   //arr是一级指针，可以传给二维数组，但是不能正确读取
//void test5(int *arr[5])   // 形参是指针数组，是一维的，可以传参，但是读取的数据不正确
//void test7(int **arr)



int main()
{
    int arr[3][5] = {0};

    test(arr);
    return 0;
}