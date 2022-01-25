/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-08 13:44:23
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-13 01:33:44
 * @FilePath: \work\DSExperiment\DSE1\E4\z_list.h
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    File : z_list.h
    实现z_list的封装声明
*/
#pragma once
#include <iostream>
using namespace std;

typedef int TypeList; //  默认类型int

class z_list //  封装链表list类
{
public:
    z_list();                         //  构造函数==>初始化链表
    ~z_list();                        //  析构函数==>删除链表
    void z_print();                   //  打印链表==>遍历节点元素输出
    int z_find(TypeList val);             //  查找函数==>查找元素并返回位置，不存在返回0
    bool z_insert(TypeList val, int pos); //  插入函数==>插入元素，失败返回false，成功返回true
    bool z_delete(TypeList val);          //  删除函数==>删除元素，失败返回false，成功返回true
    void z_reverse();                 //  翻转函数==>翻转链表
    void z_seg(TypeList val);             //  切割重构功能函数==>以基准值把单链表分割为两部分，所有小于该值的结点排在大于或等于该值的结点之前

private:
    struct Node //  Node结构体 存储链表节点数据 包含数据域data，前后驱指针pre，next
    {
        TypeList data;         //  数据域data
        struct Node *pre;  //  前驱指针pre
        struct Node *next; //  后驱指针next
    };
    struct Node *head; //  表头节点 head
};