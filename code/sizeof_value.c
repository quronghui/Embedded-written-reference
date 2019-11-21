//
// Created by quronghui on 2019/9/21.
//
/*
 * 题目一：指针数组和数组指针的计算；
 * 题目二：数组名和指针名的计算
 * 题目三：指针数组和数组名；
 * */
#include <stdio.h>
#include <string.h>

// （1）指针数组和数组指针的计算；
void sizeof_test()
{
    int (*p1)[50];  // 数组指针；先指针后数组
    int *p2[50];    // 指针数组；先数组后指针
    int a[2][50];

    for(int i = 0; i < 2; i++)
        for (int j = 0; j < 50; ++j) {
            a[i][j] = j + i * 100; // a[0][j] = 0-50; a[1][j] = 100-150;
        }
    p1 = (void *)&a;
    p2[0] = (void *)&a;

    printf("sizeof(a) = %d, sizeof(p1) = %d, sizeof(p2) = %d\n", sizeof(a), sizeof(p1), sizeof(p2));
    printf("sizeof(*a) = %d, sizeof(*p1) = %d, sizeof(*p2) = %d\n", sizeof(*a), sizeof(*p1), sizeof(*p2));
    printf("**(p1+1) = %d, *(*p1 + 1) = %d, **(p2 + 1) = %d\n", **(p1+1), *(*p1 + 1), **(p2 + 1));
}
/*
 *  sizeof(a) = 400, sizeof(p1) = 8, sizeof(p2) = 400
    sizeof(*a) = 200, sizeof(*p1) = 200, sizeof(*p2) = 8
    **(p1+1) = 100, *(*p1 + 1) = 1, **(p2 + 1) = 1651076143
 * */

// （2）数组名和指针名的计算
void sizeof_array_pointer()
{
    char *p = "abcde";
    char q[] = {"abcde"};
    printf("sizeof(p) = %d ", sizeof(p));
    printf(" sizeof(q) = %d ", sizeof(q));
    printf(" strlen(p) = %d ", strlen(p));
    printf(" strlen(q) = %d\n", strlen(q));
}
/*
 * sizeof(p) = 8  sizeof(q) = 8  strlen(p) = 7  strlen(q) = 7
 * */

// （3）指针数组和数组名；
void array_name()
{
    char *pa[4] = {"aaa","bbb","ccc","ddd"};    // 初始化的常量，放在data区;
    char pb[4] = {'a','b','c','d'};

    // 指针数组：每一次加1，跳过4bytes
    for (int i = 0; i < 4; ++i) {
        printf("%s ",*(pa+i));
    } //aaa bbb ccc ddd
    printf("\n");

    // 数组中存放相同类型的元素:每一次加1，跳过1个字节
    for (int i = 0; i < 4; ++i) {
        printf("%c ",pb[i]);
    } //a b c d
    printf("\n");

    // 如果直接进行赋值

}


int main()
{
    sizeof_test();
    sizeof_array_pointer();
    array_name();



    return 0;
}

