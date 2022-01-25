/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-08 17:15:42
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-12 20:13:48
 * @FilePath: \work\DSExperiment\DSE1\E3\z_queue.h
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    File : z_queue.h
    实现z_queue的封装声明
*/


typedef int T; //  默认类型int

class z_queue
{
public:
    z_queue();                  //  构造函数==>初始化队列
    ~z_queue();                 //  析构函数==>删除队列
    void z_push(const T &data); //  入队函数
    T z_pop();                  //  出队函数
    void z_print();             //  打印队列
    void z_reverse();           //  翻转队列

private:
    struct Node //  Node结构体 存储节点数据 包含数据域data，前后驱指针pre，next
    {
        T data;     //  数据域data
        Node *next; //  前驱指针pre
        Node *pre;  //  后驱指针next
    };
    Node *front; //  队列右端
    Node *rear;  //  队列左端
};