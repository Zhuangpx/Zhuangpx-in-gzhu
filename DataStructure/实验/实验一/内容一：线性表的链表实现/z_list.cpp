/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-08 13:44:30
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-12 17:47:29
 * @FilePath: \work\DSExperiment\DSE1\E1\z_list.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    File : z_list.cpp
    include "z_list.h"
    实现对z_list.h头文件里声明的z_list类函数定义
*/

#include "z_list.h"
// #include<iostream>
// using namespace std;

z_list::z_list() //  构造函数==>初始化链表
{
    head = new Node;
    head->next = head->pre = NULL;
    head->data = 0;
}

z_list::~z_list() //  析构函数==>删除链表
{
    Node *temp = head->next;
    while (temp != NULL)
    {
        Node *Temp = temp;
        temp = temp->next;
        delete Temp;
    }
    delete head;
}

void z_list::z_print() //  打印链表==>遍历节点元素输出
{
    Node *temp = head;         //  临时节点 初始化为表头节点
    while (temp->next != NULL) //  对节点遍历
    {
        cout << temp->next->data << '\t'; //  打印出节点数据域内容
        temp = temp->next;                //  节点后移
    }
    cout << '\n';
}

int z_list::z_find(Type val) //  查找函数==>查找元素并返回位置，不存在返回0
{
    Node *temp = head;         //  临时节点 初始化为表头节点
    int pos = 1;               //  位置初始化为1
    while (temp->next != NULL) //  对节点遍历
    {
        if (temp->next->data == val) //  找到元素
        {
            return pos; //  返回位置
        }
        pos++;             //  位置自增
        temp = temp->next; //  节点后移
    }
    return 0; //  找不到元素返回0
}

bool z_list::z_insert(Type val, int pos) //  插入函数==>插入元素，失败返回false，成功返回true
{
    Node *temp = head;         //  临时节点 初始化为表头节点
    int cnt = 1;               //  位置初始化为1
    if (pos < 1)               //  插入位置不合理
        return false;          //  插入失败
    while (temp->next != NULL) //  对节点遍历
    {
        if (cnt == pos) //  找到位置
        {
            Node *Temp = new Node;
            Temp->data = val;
            Temp->next = temp->next;
            Temp->pre = temp;
            temp->next->pre = Temp;
            temp->next = Temp;
            return true; //  插入成功
        }
        temp = temp->next;
        cnt++;
    }
    if (cnt == pos) //  找到位置
    {
        Node *Temp = new Node;
        Temp->data = val;
        Temp->next = temp->next;
        Temp->pre = temp;
        if (temp->next != NULL)
            temp->next->pre = Temp;
        temp->next = Temp;
        return true; //  插入成功
    }
    return false; //  插入失败
}

bool z_list::z_delete(Type val) //  删除函数==>删除元素，失败返回false，成功返回true
{
    Node *temp = head;         //  临时节点 初始化为表头节点
    while (temp->next != NULL) //  对节点遍历
    {
        if (temp->next->data == val) //  找到删除元素
        {
            Node *Temp = temp->next;
            temp->next = Temp->next;
            if (Temp->next != NULL)
                Temp->next->pre = temp;
            delete Temp;
            Temp = NULL;
            return true; //  删除成功
        }
        temp = temp->next;
    }
    return false; //  找不到该元素，删除失败
}

void z_list::z_reverse() //  翻转函数==>翻转链表
{
    if (head->next == NULL || head->next->next == NULL) //  特判链表为空和链表元素只有一个，此时翻转后链表为其本身
        return;
    Node *temp = head->next->next;  //  先取出首节点，它将成为最后一位
    head->next->next = NULL;    //  尾部置空
    while (temp != NULL)    //  头插法实现翻转：依次取出节点，插入头结点后继成为新的首节点
    {
        Node *Temp = temp->next;
        temp->next = head->next;
        temp->pre = head;
        head->next->pre = temp;
        head->next = temp;
        temp = Temp;
    }
    return; //  返回链表本身
}
