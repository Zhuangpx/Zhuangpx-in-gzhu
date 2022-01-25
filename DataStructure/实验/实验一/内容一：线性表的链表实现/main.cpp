/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-06 00:00:59
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-12 17:45:24
 * @FilePath: \work\DSExperiment\DSE1\E1\main.cpp
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
#include "z_list.h"

using namespace std;

#define MIN 100
#define MAX 999
#define SIZE 10

typedef int Type;

bool randInit; //   记录随机化种子是否已经初始化

Type get_randNum(Type l = MIN, Type r = MAX); //  生成并返回[l,r]的随机数

void test();    //  测试函数入口

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

    z_list l;        //  声明链表l
    Type temp;       //  临时变量temp ==> 作为函数返回值
    Type num;        //  临时变量num ==> 接收输入元素
    int pos;         //  临时变量pos ==> 接收输入位置
    bool ok = false; //  临时变量ok ==> 作为函数返回值

    //依次获得十个随机数并插入链表中
    for (int i = 0; i < SIZE; i++)
    {
        int d = get_randNum();
        cout << "$ Intsert:" << d << " in NO." << i + 1 << '\n';
        l.z_insert(d, i + 1);
        // l.z_insert(get_randNum(), i + 1);
    }

    //打印初始链表
    cout << "$ Init:\n";
    l.z_print();

    //输入元素，在链表中查找该元素
    cout << "$ Input a number to search:\n";
    cin >> num;
    temp = l.z_find(num);
    if (temp == 0) //  找不到该元素
        cout << "$ Erro : No sunch number\n";
    else //  找了该元素，输出该元素位置
        cout << "$ Find the number " << num << " is on the position of NO." << temp << '\n';

    //输入元素和位置，在链表中插入该元素
    cout << "$ Input a number and it's position to insert:\n";
    cin >> num >> pos;
    ok = l.z_insert(num, pos);
    if (ok) //  插入成功，打印链表
        l.z_print();
    else //  插入失败，插入位置不合理
        cout << "$ Error : Can not insert in this position\n";

    //输入元素，在链表中删除该元素
    cout << "$ Input a number to delete:\n";
    cin >> num;
    ok = l.z_delete(num);
    if (ok) //删除成功
        cout << "$ After deleted:\n", l.z_print();
    else //删除失败，没有该元素
        cout << "$ Error : No such number\n";

    //对链表进行翻转并打印
    cout << "$ After reversed:\n";
    l.z_reverse();
    l.z_print();

    //测试结束
    cout << "\n======TestEnd======\n";
}