/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-12-14 13:37:04
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-12-19 23:52:42
 * @FilePath: \work\DSExperiment\DSE3\main.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#include<iostream>
#include"z_Graph.hpp"
using namespace std;
void Graph_test();
// int main()
// {
//     Graph_test();
//     return 0;
// }

/*
7 9
0 1 28
0 5 10
1 6 14
1 2 16
5 4 25
6 4 24
6 3 18
2 3 12
4 3 22
*/

void Graph_test()
{
    vector<z_edge> e;
    int size;
    cin>>size;
    int cnt;
    cin>>cnt;
    for(int i=0;i<cnt;i++){
        int s,d,w;cin>>s>>d>>w;
        z_edge t1(s,d,w);
        z_edge t2(d,s,w);
        e.push_back(t1);
        e.push_back(t2);
    }
    z_graph<int> g(e,size);
    g.showG();
    cout<<"Bfs:\n";
    vector<int>bfsv;
    g.bfs(0,bfsv);
    for(auto x:bfsv)cout<<x<<' ';cout<<'\n';
    cout<<"Dfs:\n";
    vector<int>dfsv;
    g.dfs(0,dfsv);
    for(auto x:dfsv)cout<<x<<' ';cout<<'\n';
    cout<<"Dijkstra:\n";
    g.Dijkstra(0);
    cout<<"Prim:\n";
    g.showPrim(0);
    // g.Prim(0);
    system("pause");
}