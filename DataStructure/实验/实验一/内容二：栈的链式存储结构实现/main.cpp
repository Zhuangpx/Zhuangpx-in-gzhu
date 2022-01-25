/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-05 23:42:19
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-12 19:49:51
 * @FilePath: \work\DSExperiment\DSE1\E2\main.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */


/*
    File : main.cpp
    主函数，包含测试入口。
*/

#include <iostream>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include "z_stack.h"

using namespace std;

#define MIN 100
#define MAX 999
#define SIZE 10

typedef int Type;

bool randInit; //   记录随机化种子是否已经初始化

Type get_randNum(Type l = MIN, Type r = MAX); //  生成并返回[l,r]的随机数

void test(); //  测试函数入口

int main()
{
    test();
    system("pause");
    return 0;
}

Type get_randNum(Type l, Type r) //  生成并返回[l,r]的随机数
{
    if (!randInit) //  初始化随机化种子
    {
        srand((unsigned)time(0));
        randInit = 1;
    }
    return l + rand() % (r - l + 1); //  利用rand产生随机数
}

void test()
{
    //测试开始
    cout << "======TestBegin======\n";

    z_stack s; //  声明栈s

    //依次获得十个随机数并压入栈顶
    for (int i = 0; i < SIZE; i++)
    {
        int d = get_randNum();
        cout << "$ Push:" << d << '\n';
        s.z_push(d);
        //s.z_push(get_randNum());
    }

    //依次出栈并输出
    cout << "$ Pop out:\n";
    for (int i = 0; i < SIZE; i++)
    {
        if (i > 0)
            cout << '\t';
        cout << s.z_pop();
    }
    cout << '\n';

    //测试结束
    cout << "======TestEnd======\n";
}
