/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-12-13 23:35:50
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-12-18 01:28:24
 * @FilePath: \work\DSExperiment\DSE3\z_Graph.hpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#pragma once
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<stack>
#include<queue>

#ifndef MAX_DIS
#define MAX_DIS INT_MAX
#endif

#ifndef Z_MAX_SIGNED_INT
#define Z_MAX_SIGNED_INT 0x3f3f3f3f
#endif


class z_edge    //  边类
{
public:
    int source;//起点
    int destination;//终点
    int weight;//边权
    // 构造函数
    z_edge(int s=-1,int d=-1,int w=MAX_DIS) : source(s),destination(d),weight(w)
    { }
};

bool operator>(const z_edge& le, const z_edge& re)/*重载边的>运算符*/
{
    return le.weight>re.weight;
}

bool operator<(const z_edge& le, const z_edge& re)/*重载边的<运算符*/
{
    return le.weight<re.weight;
}


/*  模板 图的存储
    第一个参数为顶点数据类型 第二个参数表示存储方式 为布尔值，false表示邻接表 true表示邻接矩阵 默认是true
*/
template<class z_Type, bool List_Matrix=true>/*false-List,true-Matrix[Normal:Matrix]*/
class storage_G { }; /*边存储*/

/*  模板 邻接矩阵存图
*/
template<class z_Type>
class storage_G<z_Type, true>
{
    // int** adjacent_matrix;
    // int size;
public:
    int size;   //  顶点数
    int** adjacent_matrix;  //  二维邻接矩阵
    // stroge_G(int s):size(s); //  构造函数 参数为顶点数
    storage_G(int s):size(s)    //  构造函数 参数为顶点数
    {
        if(s==0)
        {
            adjacent_matrix=NULL;
            return;
        }
        adjacent_matrix=new int*[size];
        for(int i=0;i<s;i++)    //  初始化邻接矩阵
        {
            adjacent_matrix[i]=new int[size];
            for(int j=0;j<size;j++)
            {
                adjacent_matrix[i][j]=MAX_DIS;
            }
        }
    }
    // stroge_G(const stroge_G<z_Type,true>& temp);   //  构造函数 参数为另一邻接矩阵 可作为复制构造
    storage_G(const storage_G<z_Type,true>& temp)   //  构造函数 参数为另一邻接矩阵 可作为复制构造
    {
        size=temp.size;
        adjacent_matrix=new int*[size];
        for(int i=0;i<size;i++)
        {
            adjacent_matrix[i]=new int[size];
            for(int j=0;j<size;j++)
            {
                adjacent_matrix[i][j]=temp.adjacent_matrix[i][j];
            }
        }
    }
    // bool insertEdge(int s,int d,int weight=1);   //  插入边
    bool insertEdge(int s,int d,int weight=1)   //  插入边
    {
        if(adjacent_matrix==NULL||(s<0&&s>=this->size)||((d<0&&d>=this->size)))
            return false;
        adjacent_matrix[s][d]=weight;
        return true;
    }
    // bool eraseEdge(int s,int d); //  删除边
    bool eraseEdge(int s,int d)     //  删除边
    {
        if(adjacent_matrix==NULL||(s<0&&s>=this.size)||((d<0&&d>=this.size)))
            return false;
        adjacent_matrix[s][d]=MAX_DIS;
        return true;
    }
    // bool hasEdge(int s,int d);   //  判边是否存在
    bool hasEdge(int s,int d)   //  判边是否存在
    {
        if(adjacent_matrix==NULL||(s<0&&s>=this->size)||((d<0&&d>=this->size)))
            return false;
        return adjacent_matrix[s][d]!=MAX_DIS;
    }
    // bool getEdge(const int& s,std::vector<edge>& s_adj,bool hasGet=false);   //  获得点s邻接的边 将边存入s_adj  第三个常数是否覆盖s_adj
    bool getEdge(const int& s,std::vector<z_edge>& s_adj,bool hasGet=false)     //  获得点s邻接的边 将边存入s_adj  第三个常数是否覆盖s_adj
    {
        if(adjacent_matrix==NULL||(s<0&&s>=size))   //图无边 或 无该点
        {
            // /*debug*/std::cout<<"NULL\n";
            return false;
        }
        // /*debug*/std::cout<<"Not NULL\n";
        if(!hasGet) s_adj.clear();  //  覆盖
        for(int i=0;i<size;i++)
        {
            if(adjacent_matrix[s][i]!=MAX_DIS)  //  找到 加边
                s_adj.push_back(z_edge(s,i,adjacent_matrix[s][i]));
        }
        // /*debug*/std::cout<<"s_adj:";for(auto x:s_adj)std::cout<<x.source<<' '<<x.destination<<"\n";
        return true;
    }
    // bool getMinEdge(int s);  //获得点s的最小边
    z_edge getMinEdge(int s)    //获得点s的最小边
    {
        int s_d=-1;
        int s_d_weight=-1;
        for(int i=0;i<size;i++)
        {
            if(adjacent_matrix[s][i]<s_d_weight)
            {
                s_d=i;
                s_d_weight=adjacent_matrix[s][i];
            }
        }
        return z_edge(s,s_d,s_d_weight);
    }
    // bool hasVertex();    //  判点是否存在
    bool hasVertex(int v)   //  判点是否存在
    {
        return (v>=0&&v<size);
    }
    // bool hasGraph(); //  判图是否空
    bool hasGraph()     //  判图是否空
    {
        return adjacent_matrix!=NULL;
    }
    // int edgeWeight(int s,int d); //  获得边权
    int edgeWeight(int s,int d) //  获得边权
    {
        if(adjacent_matrix==NULL) return MAX_DIS;
        else return adjacent_matrix[s][d];
    }
    // void showG();    //  打印邻接矩阵
    void showG()    //  打印邻接矩阵
    {
        if(adjacent_matrix==NULL) return;
        std::cout<<"Show the Graph by Adjacent Matrix as: [Source]:[Destination,(weight)]... \n";
        for(int i=0;i<size;i++)
        {
            std::cout<<"["<<i<<"]:";
            for(int j=0;j<size;j++)
            {
                if(adjacent_matrix[i][j]!=MAX_DIS)
                    std::cout<<"["<<j<<",("<<adjacent_matrix[i][j]<<")]";
                else std::cout<<"["<<j<<",(none)]";
            }
            std::cout<<'\n';
        }
        std::cout<<std::endl;
    }
};

/* 模板 邻接表存图
*/
template<class z_Type>
class storage_G<z_Type, false>
{

};


/*  模板 图
*/
template<class z_Type, bool List_Matrix=true>
class z_graph
{
    storage_G<z_Type,List_Matrix> G;/*存图*/
    std::map<int,z_Type> V;/*点权*/
public:
    // z_graph(std::vector<z_edge> edges,int V_size) : G(List_Matrix ? V_size:0)   //  构造函数 参数为边和顶点数
    z_graph(std::vector<z_edge> edges,int V_size) : G(List_Matrix ? V_size:0)   //  构造函数 参数为边和顶点数
    {
        for(const auto& e:edges)
        {
            if(!(e.source>=0&&e.source<this->G.size)||!(e.destination>=0&&e.destination<this->G.size)) continue;
            else insertEdge(e.source,e.destination,e.weight);
        }
    }
    // z_graph(const z_graph<z_Type,List_Matrix>& tempG) : G(List_Matrix ? tempG.G.size:0) //  构造函数 参数为另一张图
    z_graph(const z_graph<z_Type,List_Matrix>& tempG) : G(List_Matrix ? tempG.G.size:0) //  构造函数 参数为另一张图
    {
        this->V=tempG.V;
        G=tempG.G;
    }
    // bool hasVertex(int idex)    //  判边存在
    bool hasVertex(int idex)    //  判点存在
    {
        return G.hasVertex(idex);
    }
    // bool hasEdge(int s,int d)   //  判边存在
    bool hasEdge(int s,int d)   //  判边存在
    {
        return G.hasEdge(s,d);
    }
    // bool getEdge(const int& s,std::vector<z_edge>& s_adj,bool hasGet=false) //  取边集
    bool getEdge(const int& s,std::vector<z_edge>& s_adj,bool hasGet=false) //  取边集
    {
        return G.getEdge(s,s_adj,hasGet);
    }
    // bool insertEdge(int s,int d,int weight=1)   //  加边
    bool insertEdge(int s,int d,int weight=1)   //  加边
    {
        if(weight<0||!G.hasVertex(s)||!G.hasVertex(d))
            return false;
        return G.insertEdge(s,d,weight);
    }
    // bool eraseEdge(int s,int d) //  删边
    bool eraseEdge(int s,int d) //  删边
    {
        return G.eraseEdge(s,d);
    }
    // int edgeWeight(int s,int d) //  边权
    int edgeWeight(int s,int d) //  边权
    {
        return G.edgeWeight(s,d);
    }
    // int size()  //  的点数
    int size()  //  的点数
    {
        return G.size();
    }
    // void showG()    //  打印图
    void showG()    //  打印图
    {
        G.showG();
    }
    // void bfs(int start,std::vector<int>& bfsv)  //  BFS 序列返回bfsv
    void bfs(int start,std::vector<int>& bfsv)  //  BFS 序列返回bfsv
    {
        std::vector<z_edge> bfse;
        // std::vector<int> bfsv;
        // std::set<int> st;
        std::map<int,bool> mp;
        std::queue<int> que;
        que.push(start);
        // set.insert(start);
        mp[start]=true;
        while(!que.empty())
        {
            int now=que.front();
            que.pop();
            bfsv.push_back(now);
            if(G.getEdge(now,bfse))
            {
                for(const auto& x:bfse)
                {
                    if(!mp[x.destination])
                    {
                        que.push(x.destination);
                        mp[x.destination]=true;
                    }
                }
            }
            else
                continue;
        }
        // for(auto x:bfsv)std::cout<<x<<' ';std::cout<<'\n';
        // std::cout<<std::endl;
    }
    // void dfs(int start,std::vector<int>& dfsv)  //  DFS 序列返回dfsv
    void dfs(int start,std::vector<int>& dfsv)  //  DFS 序列返回dfsv
    {
        if(!this->G.hasVertex(start)) return;
        std::map<int,bool> mp;
        dfs(start,dfsv,mp);
        // for(auto x:dfsv)std::cout<<x<<' ';std::cout<<'\n';
        // std::cout<<std::endl;
    }
    // void dfs(int now,std::vector<int>& dfsv,std::map<int,bool>& mp) //  DFS 序列返回dfsv
    void dfs(int now,std::vector<int>& dfsv,std::map<int,bool>& mp) //  DFS 序列返回dfsv
    {
        if(!this->G.hasVertex(now)) return;
        dfsv.push_back(now);
        mp[now]=true;
        std::vector<z_edge> dfse;
        // std::vector<int> dfsv;
        if(this->G.getEdge(now,dfse))
        {
            for(const auto& x:dfse)
            {
                if(!mp[x.destination])
                    dfs(x.destination,dfsv,mp);
            }
        }
    }
    // void Dijkstra(int start=0)  //  Dijkstra 以start为起点求到各点的最短路径和最短距离
    void Dijkstra(int start=0)  //  Dijkstra 以start为起点求到各点的最短路径和最短距离
    {
        int* dis=new int[this->G.size]; //  记点到起点距离
        int* vis=new int[this->G.size]; //  记点是否寻找过
        int* path=new int[this->G.size];//  记路径 path[i]表示i的前一个点
        int* a_path=new int[this->G.size];  //  临时路径 作为输出
        int size=this->G.size;  //  顶点数
        for(int i=0;i<size;i++) //  初始化
        {
            int n_dis=this->G.adjacent_matrix[start][i];
            if(n_dis==MAX_DIS) path[i]=-1;
            else path[i]=start;
            dis[i]=n_dis;   //初始化距离
            vis[i]=0;       //初始化为未寻找过
        }
        path[start]=0;  //  起点
        vis[start]=1;   //  起点先加入
        for(int cnt=1;cnt<size;cnt++)//cnt-1个点 需要cnt次寻找
        {
            int min_dis=MAX_DIS;
            int pos=-1;
            for(int i=0;i<size;i++) //  寻找最近点
            {
                if(!vis[i]&&min_dis>dis[i])
                {
                    min_dis=dis[i];
                    pos=i;
                }
            }
            if(pos==-1) continue;
            else vis[pos]=1;
            for(int i=0;i<size;i++) //  更新未找过的点
            {
                int n_dis=this->G.adjacent_matrix[pos][i];
                if(!vis[i])
                {
                    if(n_dis<MAX_DIS&&n_dis+dis[pos]<dis[i])
                    {
                        dis[i]=dis[pos]+n_dis;
                        path[i]=pos;
                    }
                }
            }
        }
        std::cout<<"Show the shortest path from "<<start<<" to others by Dijkstra as : [Source]->[Destination](weight):->[..]->[..]..\n";
        for(int i=0;i<size;i++) //  打印各点最短路
        {
            if(!vis[i]) //  不连通
                std::cout<<"["<<start<<"]->["<<i<<"]:[none]\n";
            if(vis[i]&&i!=start)
            {
                std::cout<<"["<<start<<"]->["<<i<<"]("<<dis[i]<<"):";
                //逆序得到路径上的点
                int cnt=0;
                a_path[cnt]=i;
                int _next=path[i];
                while(_next!=start)
                {
                    cnt++;
                    a_path[cnt]=_next;
                    _next=path[_next];
                }
                cnt++;
                a_path[cnt]=start;
                for(int j=cnt;j>=0;j--)
                {
                    std::cout<<a_path[j]<<"->";
                }
                std::cout<<"End\n";
            }
        }
        std::cout<<std::endl;
        delete[] dis;
        delete[] vis;
        delete[] path;
        delete[] a_path;
    }
    // void showPrim(int start=0)  //  Prim 以start为根 构造最小生成树
    void showPrim(int start=0)  //  Prim 以start为根 构造最小生成树 并打印出来
    {
        Prim(start).showG();
    }
    // z_graph<z_Type,List_Matrix> Prim(int start=0)   //  Prim 以start为根 构造最小生成树
    z_graph<z_Type,List_Matrix> Prim(int start=0)   //  Prim 以start为根 构造最小生成树
    {
        std::vector<z_edge> _edge;  //  存生成树的边集
        // std::priority_queue<z_edge,std::vector<z_edge>,std::greater<>> _edge_que;
        // std::map<int,bool> _mp;
        // std::map<int,int> dis;
        std::vector<int> _dis(this->G.size);    //  记各点到生成树最小距离
        for(int i=0;i<this->G.size;i++) _dis[i] = MAX_DIS;  //  初始化距离为无穷大
        std::vector<int> _adj(this->G.size);    //  记各点到生成树最小距离的邻点
        // std::map<int,bool> _vis;
        for(int i=0;i<this->G.size;i++)         //  初始化边和点
        {
            _dis[i] = G.adjacent_matrix[start][i];
            _adj[i] = start;
        }
        _dis[start] = 0;    //  根节点先进 距离为0时表示已加入生成树
        // _vis[start] = 1;
        int _size = 0;
        for(int cnt=0;cnt<this->G.size;cnt++)   //  遍历所有顶点
        {
            int _pos=-1;
            for(int i=0;i<this->G.size;i++) //  找出最近点
            {
                if(/*!_vis[i]*/_dis[i]&&(_pos==-1||_dis[_pos]>_dis[i])) _pos=i;
            }
            if(_pos==-1)    break;
            if(/*_pos!=start&&*/_dis[_pos]==MAX_DIS)   break;
            //  加入两条无向边
            _edge.push_back(z_edge(_adj[_pos],_pos,_dis[_pos]));
            _edge.push_back(z_edge(_pos,_adj[_pos],_dis[_pos]));
            _dis[_pos] = 0; //距离为0 表示已加入生成树
            for(int i=0;i<this->G.size;i++) //  更新树外点
            {
                if(_dis[i]&&this->G.adjacent_matrix[_pos][i]<_dis[i])
                {
                    _dis[i] = this->G.adjacent_matrix[_pos][i];
                    _adj[i] = _pos;
                }
            }
        }
        return z_graph(_edge,this->G.size); //  返回生成树 以邻接矩阵存图
    }
};
