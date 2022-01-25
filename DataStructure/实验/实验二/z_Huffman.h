/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-18 18:42:59
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-28 17:22:43
 * @FilePath: \work\DSExperiment\DSE2\z_Huffman.h
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    File: z_Huffman.h
    哈夫曼头文件。
    包含哈夫曼数节点类，哈夫曼树编码类，哈夫曼类和统计函数声明
    对应行为定义在文件z_Huffman.cpp内
*/

// #pragma
#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <map>

using namespace std;

// const int MAXSIZE = 100000;
// 最大节点规模
#ifndef MAXSIZE
#define MAXSIZE 1000
#endif
// const int MAXWEI = 100000;
// 最大权重
#ifndef MAXSWEI
#define MAXWEI 100000
#endif

void CodeCalcu(char str[], char s[], int w[], int &len); //统计字符

class HfNode //哈夫曼树节点类
{
public:
    char data;                                       //数据域
    int weight;                                      //权重
    int parent;                                      //父节点
    int lchild;                                      //左子节点
    int rchild;                                      //右子节点
    int idx;                                         //在存储数组中的编号
    HfNode() : parent(-1), lchild(-1), rchild(-1) {} //构造函数=>初始化
    friend bool operator<(HfNode x, HfNode y)        //重载小于号运算符
    {
        if (x.weight != y.weight) //权重第一级
            return x.weight > y.weight;
        else
            return x.data < y.data; //数据域第二级
    }
};

class HfCode //哈夫曼树编码类
{
public:
    stack<char> hcd;
};

class z_huffman //哈夫曼类
{
public:
    z_huffman();                             //无参构造函数
    z_huffman(char s[], int w[], int len);   //含参构造函数
    void z_init(char s[], int w[], int len); //初始化函数
    void z_huffTree();                       //哈夫曼树初始化
    void z_huffCode();                       //哈夫曼编码初始化
    void z_displayHfCode();                  //输出编码
    void z_show(char s[]);                   //将原文压缩和解压并输出
    ~z_huffman();                            //析构函数
    map<stack<char>,char>hashCode;           //哈希表 将原文压缩成编码映射到字符
    vector<stack<char>>showString;           //存下原文编码 用于解压输出原文
private:
    int size;             //有效字符大小规模
    HfNode hfn[MAXSIZE];  //存储哈夫曼树节点
    HfCode hfcd[MAXSIZE]; //存储哈夫曼编码节点
};
