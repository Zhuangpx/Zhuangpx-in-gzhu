/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-13 00:45:23
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-13 23:10:22
 * @FilePath: \work\DSExperiment\DSE1\E4\z_maze.h
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    File : z_maze.h
    实现z_maze的封装声明
*/

#pragma once
#include "z_list.h"
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;
class z_maze
{
public:
    z_maze(); //  无参构造
    z_maze(const vector<string> &in_Maze /*迷宫地图*/ /*const vector<vector<char>> &in_Maze*/, char in_obs /*障碍字符*/, char in_nor /*正常可行路字符*/, char in_go /*解决方案字符*/, int in_row /*行数*/, int in_col /*列数*/, int in_sx /*起点横坐标*/, int in_sy /*起点纵坐标*/, int in_gx /*终点点横坐标*/, int in_gy /*终点纵坐标*/);
    ~z_maze();
    int z_findPath();   //  寻找最短路径并返回最短路长度                                                                                 //  打印最短路径
    void z_printPath(); //  输出最短路径解决方案
    void debug();       //  调试

private:
    // vector<vector<char>> Maze;                        //  迷宫地图
    vector<string> Maze; //  迷宫地图
    vector<string> MazePath;
    int row;                                          //  行数
    int col;                                          //  列数
    char obs;                                         //  障碍字符
    char nor;                                         //  正常可行路字符
    char go;                                          //  解决方案字符
    int sx, sy;                                       // 起点坐标
    int gx, gy;                                       //  终点坐标
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //4个方向移动的向量
    // pair<int,int>Node;
    struct Node //点坐标
    {
        int x;
        int y;
    };
    vector<vector<int>> dix;  //  距离
    vector<vector<int>> path; //  路径
    vector<vector<int>> pre;  //  前继
    map<int, Node> point;     //  搜索层-点映射
    int cnt;                  //  搜索层
};