/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-08 17:15:51
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-12 20:31:54
 * @FilePath: \work\DSExperiment\DSE1\E3\z_queue.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    File : z_queue.cpp
    include "z_queue.h"
    实现对z_queue.h头文件里声明的z_queue类函数定义
*/

#include "z_queue.h"
#include <iostream>
using namespace std;

z_queue::z_queue() //  构造函数==>初始化队列
{
    rear = new Node;
    rear->next = rear->pre = NULL;
    rear->data = 0;
    front = rear;
}

z_queue::~z_queue() //  析构函数==>删除队列
{
    while (rear != front)
    {
        rear = rear->pre;
        delete rear->next;
        rear->next = NULL;
    }
}

void z_queue::z_push(const T &data) //  入队函数
{
    rear->pre = new Node;
    rear->pre->next = rear;
    rear = rear->pre;
    rear->next->data = data;
    rear->pre = NULL;
    rear->data = 0;
}

T z_queue::z_pop() //  出队函数
{
    T res = 0;
    if (front != rear)
    {
        front = front->pre;
        res = front->next->data;
        delete front->next;
        front->next = NULL;
    }
    else
        cerr << "Error:Queue is empty\n"; //  队列已空
    return res;
}

void z_queue::z_print() //  打印队列
{
    Node *temp = front;  //  临时节点 初始化为右节点
    while (temp != rear) //  对节点遍历
    {
        cout << temp->data << '\t'; //  打印出节点数据域内容
        temp = temp->pre;           //  节点左移
    }
    cout << '\n';
}

void z_queue::z_reverse() //   翻转队列
{
    Node *l = front, *r = rear;
    while (l != r) //  按meet in middle算法思维，依次交换数据域
    {
        swap(r->next->data, l->data);
        if (l->next == r || r->pre == l)
            return;
        l = l->pre;
        r = r->next;
    }
}