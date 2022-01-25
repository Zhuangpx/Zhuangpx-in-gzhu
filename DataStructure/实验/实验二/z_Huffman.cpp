/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-18 18:42:42
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-28 18:18:58
 * @FilePath: \work\DSExperiment\DSE2\z_Huffman.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    File: z_Huffman.cpp
    包含z_Huffman.h中各行为定义
*/

#include <map>
#include <queue>
#include <cstring>
#include "z_Huffman.h"
using namespace std;

//无参构造函数
z_huffman::z_huffman() {}

//含参构造函数
z_huffman::z_huffman(char s[], int w[], int len)
{
    z_init(s, w, len);
}

//析构函数
z_huffman::~z_huffman() {}

//初始化函数
void z_huffman::z_init(char s[], int w[], int len)
{
    size = len;
    for (int i = 0; i < size; i++)
    {
        HfNode *temp = new HfNode();
        temp->data = s[i];
        temp->weight = w[i];
        temp->idx = i;
        hfn[i] = *temp;
    }
}

//哈夫曼树初始化
void z_huffman::z_huffTree()
{
    // for (int i = 0; i < 2 * size - 1; i++)
    // {
    //     hfn[i].parent = hfn[i].lchild = hfn[i].rchild = -1;
    // }
    //优先队列 存储节点 由于重载了小于运算符 能按权重第一 数据域第二的关键字排序
    priority_queue<HfNode> q;
    for (int i = 0; i < size; i++)
    {
        HfNode temp = hfn[i];
        q.push(temp);
    }
    int cnt = size; //有效节点0~size 无效节点size~2*size-1
    while (q.size() >= 2 /*&& cnt < 2 * size - 1*/)
    {
        //每次取出两个权重最小的节点
        HfNode ln = q.top();
        q.pop();
        HfNode rn = q.top();
        q.pop();
        // cout << "Debug: " << ln.data << ' ' << ln.weight << "  " << rn.data << ' ' << rn.weight << '\n';
        //对当前两个节点合成
        int l = ln.idx, r = rn.idx;
        hfn[cnt].weight = hfn[l].weight + hfn[r].weight;
        hfn[cnt].lchild = hfn[l].idx;
        hfn[cnt].rchild = hfn[r].idx;
        hfn[cnt].idx = cnt;
        hfn[l].parent = hfn[r].parent = cnt;
        //将新生成的节点扔回去
        q.push(hfn[cnt]);
        cnt++;
    }
    //还剩下一个节点
    if (!q.empty())
    {
        HfNode last = q.top();
        q.pop();
        hfn[cnt].weight = hfn[size].weight + hfn[last.idx].weight;
        hfn[cnt].lchild = hfn[size].idx;
        hfn[cnt].rchild = last.idx;
        hfn[cnt].parent = -1;
        hfn[cnt].idx = cnt;
    }
}

//哈夫曼编码初始化
void z_huffman::z_huffCode()
{
    int chi;
    int par;
    for (int i = 0; i < size; i++)
    {
        chi = i;
        par = hfn[chi].parent;
        hfcd[i].hcd.push('#'); //栈底哨兵
        while (par != -1)
        {
            if (hfn[par].lchild == chi) //   左 置0
                hfcd[i].hcd.push('0');
            else
                hfcd[i].hcd.push('1'); //  右 置1
            chi = par;
            par = hfn[par].parent;
        }
    }
}

//输出编码
void z_huffman::z_displayHfCode()
{
    for (int i = 0; i < size; i++)
    {
        cout << hfn[i].data << " 's Huffman Code is : ";
        // while (hfcd[i].hcd.top() != '#')
        // {
        //     cout << hfcd[i].hcd.top();
        //     hfcd[i].hcd.pop();
        // }
        stack<char> temp = hfcd[i].hcd;
        while (temp.top() != '#')
        {
            cout << temp.top();
            temp.pop();
        }
        cout << '\n';
    }
}

//将原文压缩和解压并输出
void z_huffman::z_show(char s[])
{
    //输出压缩结果
    cout << "\nCompress:\n";
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] > 127 || s[i] < 33) //无效字符
        {
            cout << s[i];
            stack<char> p;
            p.push(s[i]);
            showString.push_back(p);
        }
        else //有效字符
        {
            int j = 0;
            while (hfn[j].data != s[i])
                j++;
            //cout << hfn[j].data;
            stack<char> temp = hfcd[j].hcd; //将编码和字符映射
            hashCode[temp] = s[i];
            showString.push_back(temp);
            while (temp.top() != '#')
            {
                cout << temp.top();
                temp.pop();
            }
        }
    }
    cout << '\n';
    //输出解压结果
    cout << "\nDecompress:\n";
    for (auto i : showString)
    {
        if (i.size() == 1 && i.top() > 127 || i.top() < 33)
            cout << i.top();
        else
            cout << hashCode[i];
    }
}

//统计字符
void CodeCalcu(char str[], char s[], int w[], int &len)
{
    map<char, int> mp; //哈希映射字符和出现次数
    len = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        //if(str[i]>='A'&&str[i]<='Z')str[i]=tolower(str[i]);
        // if (!(str[i]>='a'&&str[i]<='z') && !(str[i]>='A'&&str[i]<='Z'))
        //     continue;
        // if (str[i] == ' ')
        //     continue;
        if (str[i] > 127 || str[i] < 33) //非有效字符
            continue;
        if (mp[str[i]] == 0)
        {
            mp[str[i]]++;
            s[len++] = str[i]; //第一次出现 加入
        }
        else
        {
            mp[str[i]]++;
        }
    }
    int cnt = 0;
    for (auto i : mp)
    {
        w[cnt++] = i.second; //权值赋值
    }
}
