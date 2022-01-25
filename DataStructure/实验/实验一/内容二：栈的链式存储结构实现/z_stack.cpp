/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-08 16:51:45
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-09 11:56:17
 * @FilePath: \apricity\work\DSExperiment\DSE1\E2\z_stack.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    File : z_stack.cpp
    include "z_stack.h"
    实现对z_stack.h头文件里声明的z_stack类函数定义
*/

#include "z_stack.h"
#include <iostream>
using namespace std;

z_stack::z_stack() //  构造函数==>初始化栈
{
    head = new Node;
    head->next = NULL;
    head->pre = NULL;
    head->data = 0;
}

z_stack::~z_stack() //  析构函数==>删除栈
{
    while (head->pre != NULL)
    {
        head = head->pre;
        delete head->next;
        head->next = NULL;
    }
}

void z_stack::z_push(const Type &data) //  入栈函数==>将元素压入占顶
{
    head->next = new Node;
    head->next->data = data;
    head->next->next = NULL;
    head->next->pre = head;
    head = head->next;
}

Type z_stack::z_pop() //  出栈函数==>将栈顶元素弹出并返回
{
    Type res = 0;
    if (head->pre != NULL)
    {
        head = head->pre;
        res = head->next->data;
    }
    else    //  错误检查：栈已空
        cerr << "Error:Stack is empty\n";
    return res;
}