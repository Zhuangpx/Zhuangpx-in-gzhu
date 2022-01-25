/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-08 16:51:37
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-13 01:35:15
 * @FilePath: \work\DSExperiment\DSE1\E4\z_stack.h
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    File : z_stack.h
    实现z_stack的封装声明
*/
#pragma once
#include <iostream>
using namespace std;

typedef char TypeStack; //  默认类型int

class z_stack //  封装stack类
{
public:
    z_stack();                     //  构造函数==>初始化栈
    ~z_stack();                    //  析构函数==>删除栈
    void z_push(const TypeStack &data); //  入栈函数==>将元素压入占顶
    TypeStack z_pop();                  //  出栈函数==>将栈顶元素弹出并返回
    TypeStack z_top();                  //  查看栈顶元素
    bool z_empty();                //  栈空判断

private:
    struct Node //  Node结构体 存储节点数据 包含数据域data，前后驱指针pre，next
    {
        TypeStack data;  //  数据域data
        Node *next; //  前驱指针pre
        Node *pre;  //  后驱指针next
    };
    Node *head; //  表头节点 head
};
