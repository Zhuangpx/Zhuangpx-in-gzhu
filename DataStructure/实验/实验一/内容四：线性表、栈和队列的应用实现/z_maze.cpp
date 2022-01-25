/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-13 00:45:34
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-13 23:15:59
 * @FilePath: \work\DSExperiment\DSE1\E4\z_maze.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    File : z_maze.cpp
    include "z_maze.h"
    实现对z_lmaze.h头文件里声明的z_maze类函数定义
*/

#include "z_maze.h"
using namespace std;

z_maze::z_maze() {}

z_maze::z_maze(const vector<string> &in_Maze /*迷宫地图*/ /*const vector<vector<char>> &in_Maze*/, char in_obs /*障碍字符*/, char in_nor /*正常可行路字符*/, char in_go /*解决方案字符*/, int in_row /*行数*/, int in_col /*列数*/, int in_sx /*起点横坐标*/, int in_sy /*起点纵坐标*/, int in_gx /*终点点横坐标*/, int in_gy /*终点纵坐标*/) //  初始化各参数
{
    cnt = 0;
    obs = in_obs;
    nor = in_nor;
    go = in_go;
    row = in_row;
    col = in_col;
    sx = in_sx;
    sy = in_sy;
    gx = in_gx;
    gy = in_gy;
    for (auto x : in_Maze)
        Maze.push_back(x), MazePath.push_back(x);
    // for (auto x : in_Maze)
    //     Maze.push_back(x);
    for (int i = 0; i < row; i++)
    {
        vector<int> temp;
        for (int j = 0; j < col; j++)
        {
            temp.push_back(-1);
        }
        dix.push_back(temp);
    }
    for (int i = 0; i < row; i++)
    {
        vector<int> temp;
        for (int j = 0; j < col; j++)
        {
            temp.push_back(-1);
        }
        path.push_back(temp);
        pre.push_back(temp);
    }
}

z_maze::~z_maze() {}

int z_maze::z_findPath() //  寻找最短路径并返回
{
    queue<Node> que;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            dix[i][j] = -1;                                 //  所有的位置都初始化为-1
    que.push(Node{sx, sy});                                 //  将起点加入队列中
    dix[sx][sy] = 0, path[sx][sy] = 0, point[0] = {sx, sy}; //  并把这一地点的距离设置为0
    while (!que.empty())                                    //  不断循环直到队列为空
    {
        Node p = que.front();       //  从队列的最前段取出元素
        que.pop();                  //  取出后从队列中删除该元素
        if (p.x == gx && p.y == gy) //  找到终点
            break;
        for (int i = 0; i < 4; i++) //四个方向的循环
        {
            int nx = p.x + dx[i], ny = p.y + dy[i];                                                     //  移动后的位置标记为(nx,ny)
            if (0 <= nx && nx < row && 0 <= ny && ny < col && Maze[nx][ny] != obs && dix[nx][ny] == -1) //  判断是否可以移动以及是否访问过(即d[nx][ny]!=-1）
            {
                que.push(Node{nx, ny});          //     可以移动，添加到队列
                dix[nx][ny] = dix[p.x][p.y] + 1; //     到该位置的距离为到p的距离+1
                path[nx][ny] = ++cnt;            //     层次点记录
                pre[nx][ny] = path[p.x][p.y];    //     前继点记录
                point[cnt] = {nx, ny};           //     层次-点映射
            }
        }
    }
    return dix[gx][gy];
}

void z_maze::z_printPath()
{
    int now = cnt;
    if (dix[gx][gy] == -1)
    {
        cerr << "Error : No such path\n";
        return;
    }
    // queue<Node> ansPath;
    Node temp;
    while (cnt >= 0)    //  迭代回转输出
    {
        temp = point[cnt];
        MazePath[temp.x][temp.y] = go;
        cnt = pre[temp.x][temp.y];
    }
    MazePath[temp.x][temp.y] = go;
    MazePath[sx][sy] = go;
    for (auto x : MazePath)
        cout << x << '\n';
}

void z_maze::debug()
{
    cout << "debug:\n";
    cout << "dix:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << dix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "Maze:\n";
    for (int i = 0; i < row; i++)
        cout << Maze[i] << '\n';
    cout << "MazePath:\n";
    for (int i = 0; i < row; i++)
        cout << MazePath[i] << '\n';
}
