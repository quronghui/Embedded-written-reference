//
// Created by quronghui on 2019/9/15.
//
// 题目：实现C语言实现程序跳转到绝对地址0x100000处执行

#include <stdio.h>

typedef void(*convert)() ;  // typedef定义了一个函数指针；


void func(void)
{
    printf("hello.\n");
}

int main()
{
    // (1) 他们的结果是一样的
    // func是函数的首地址，它的类型是void ();
    printf("func = %d\n",func);
    // &func表示一个指向函数void func(void)这个对象的地址，它的类型是void (*)()
    printf("&func = %d\n",&func);

    // (2)在调用一个函数的时候，也有两种方法
    void (*func_p)(void) = func;
    (*func_p)();    //调用函数时，加一个括号
    (func_p)();     //void * 参数可以是任何值
    func_p();       //后面两者也是对的，只是不那么用
    func();

    //(3)实现程序跳转到绝对地址0x100000处执行
    /*  void (*)(void); --> int * ;  //void *：是一个数据类型，返回值为空，参数为空；
     * ( void (*)(void) ); --> ( int * );   //加了一个括号之后，代表强制类型转换
     * ( void (*)(void) )0x100000;          //把0x100000强制转化为一个函数指针
     * ( *( void (*)(void) )0x100000 )();     // 第一种方式实现
     * ( ( void (*)(void) )0x100000 )();      // 第二种方式：就是调用这个函数，外层再加个括号，后面在加一对括号
     *
    */
//    ( ( void (*)(void) )0x100000 )();

    // (4) 能不能通过typedef来简化表达式
    puts("By typedef: ");
    convert func_pp = func;
    (func_pp)();
}
