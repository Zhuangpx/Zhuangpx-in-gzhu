/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-08 16:51:37
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-12 18:47:05
 * @FilePath: \work\DSExperiment\DSE1\E2\z_stack.h
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    File : z_stack.h
    实现z_stack的封装声明
*/
#pragma once
#include <iostream>
using namespace std;

typedef int Type; //  默认类型int

class z_stack //  封装stack类
{
public:
    z_stack();                     //  构造函数==>初始化栈
    ~z_stack();                    //  析构函数==>删除栈
    void z_push(const Type &data); //  入栈函数==>将元素压入占顶
    Type z_pop();                  //  出栈函数==>将栈顶元素弹出并返回

private:
    struct Node //  Node结构体 存储节点数据 包含数据域data，前后驱指针pre，next
    {
        Type data;  //  数据域data
        Node *next; //  前驱指针pre
        Node *pre;  //  后驱指针next
    };
    Node *head; //  表头节点 head
};
