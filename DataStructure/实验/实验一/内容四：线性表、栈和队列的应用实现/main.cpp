/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-09 11:43:40
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-13 23:16:16
 * @FilePath: \work\DSExperiment\DSE1\E4\main.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    File : main.cpp
    包含测试入口
*/

#include <iostream>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <time.h>
#include <vector>
#include "ParenthesesMatching.h"
#include "z_list.h"
#include "z_maze.h"
using namespace std;

#define MIN 100
#define MAX 999
#define SIZE 10

bool randInit; //   记录随机化种子是否已经初始化

int get_randNum(int l = MIN, int r = MAX); //  生成并返回[l,r]的随机数

void test(); //  测试入口

inline void ParenthesesMatchingTest(); //  括号匹配测试

inline void ListSegTest(); //  链表切割重构排序测试

inline void MazeTest(); //  迷宫测试

int main()
{
    test();
    system("pause");
    return 0;
}

void test()
{
    cout << "$ ====== Test begin ====== $\n";
    ParenthesesMatchingTest();
    cout << '\n';
    ListSegTest();
    cout << '\n';
    MazeTest();
    cout << "\n$ ====== Test End ====== $\n";
}

inline void ParenthesesMatchingTest()
{
    cout << "$ ======ParenthesesMatchingTest Begin====== $\n";
    string s;
    cout << "$ Input a string of parentheses to judge matching:\n";
    cin >> s;
    PM zpx;
    cout << (zpx.IsMatching(s) ? "Legal nested (Matching success)\n" : "Illegal nested (Matching failed)\n");
    cout << "\n$ ======ParenthesesMatchingTest End====== $\n";
}

inline void ListSegTest()
{
    cout << "$ ======ListSegTest Begin====== $\n";
    z_list l; //  声明链表l
    int temp;
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
    //切割重构排序
    cout << "$ Input a number to segmented:\n";
    cin >> temp;
    l.z_seg(temp);
    cout << "$ After segmented:\n";
    l.z_print();
    cout << "\n$ ======ListSegTest end====== $\n";
}

int get_randNum(int l, int r) //  生成并返回[l,r]的随机数
{
    if (!randInit) //  初始化随机化种子
    {
        srand((unsigned)time(0));
        randInit = 1;
    }
    return l + rand() % (r - l + 1); //  利用rand产生随机数
}

inline void MazeTest()
{
    cout << "$ ======MazeTest Begin====== $\n";

    // vector<vector<char>> maze;
    vector<string> maze;
    int row, col;
    char obs, nor, go;
    int sx, sy;
    int gx, gy;
    // 输入行和列
    cout << "$ Input the row and col:\n";
    cin >> row >> col;
    //输入障碍和正常可走路径符号
    cout << "$ Input the oobstacles and normal char:\n";
    cin >> obs >> nor;
    //输入解决方法符号
    cout << "$ Input the solution char:\n";
    cin >> go;
    //输迷宫地图
    cout << "$ Input the maze:\n";
    for (int i = 0; i < row; i++)
    {
        string s;
        cin >> s;
        maze.push_back(s);
    }
    //输入起点坐标
    cout << "$ Input the begining point (x and y):\n";
    cin >> sx >> sy;
    //输入终点坐标
    cout << "$ Input the ending point (x and y):\n";
    cin >> gx >> gy;
    //实例化z_maze类对象px
    z_maze px(maze, obs, nor, go, row, col, sx, sy, gx, gy);
    //获取最短路径
    int ans = px.z_findPath();
    // int ans = -1;
    if (ans == -1) //  不存在即无解
        cout << "$ The maze without a solution\n";
    else //  存在则输出
        cout << "$ The maze's minimum path is " << ans << ":\n", px.z_printPath();

    // px.debug();

    cout << "\n$ ======MazeTest end====== $\n";
}
