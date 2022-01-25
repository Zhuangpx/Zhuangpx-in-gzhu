/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-05 14:57:31
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-12 20:21:57
 * @FilePath: \work\DSExperiment\DSE1\E3\main.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    File : main.cpp
    主函数，包含测试入口。
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "z_queue.h"
using namespace std;

#define MIN 100
#define MAX 999
#define SIZE 10

typedef int T; //  默认类型int

bool randInit; //   记录随机化种子是否已经初始化

T get_randNum(T l = MIN, T r = MAX); //  生成并返回[l,r]的随机数

void test(); //  测试函数入口

int main()
{
    test();
    system("pause");
    return 0;
}

T get_randNum(T l, T r) //  生成并返回[l,r]的随机数
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

    z_queue q; //  声明队列q


    //依次获得十个随机数并入队
    for (int i = 0; i < SIZE; i++)
    {
        int d = get_randNum();
        cout << "$ Push:" << d << '\n';
        q.z_push(d);
        // q.z_push(get_randNum());
    }

    //初始队列
    cout << "$ Init:\n";
    q.z_print();

    //翻转
    q.z_reverse();

    //翻转后队列
    cout << "$ After reversed (push out):\n";
    for (int i = 0; i < SIZE; i++)
    {
        if (i > 0)
            cout << '\t';
        cout << q.z_pop();
    }
    cout << '\n';

    //测试结束
    cout << "\n======TestEnd======\n";
}