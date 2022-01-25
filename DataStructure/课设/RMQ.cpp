/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-12-17 00:18:41
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-12-29 10:02:38
 * @FilePath: \work\DSExperiment\DSE\RMQ.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */
#include <stdio.h>
#include <iostream>
#include <time.h>
//利用宏定义规定数据范围
#define N 100005
#define M 1000005
#define LG 20
typedef struct edge //结构体edge表示存边节点
{
    int v;
    struct edge *next;
} edge;                          //边的struct
edge *head[N], G[N << 1];        //存边的数组
int cnt, lg[N];                  //cnt为边的数量,lg为预处理的log值,由于浮点的log运算较慢,所以此处预处理出log函数值能节省时间
void addedge(int u, int v) { G[cnt] = (edge){v, head[u]}, head[u] = &G[cnt++]; } //加边
int dfn[N << 1], dep[N << 1], dfncnt, pos[N], st[LG][N << 1];
//dfn是存欧拉序列的数组,dep为欧拉序列元素对应的深度,pos为树上点在欧拉序列最先出现的地方,st则为st表预处理所需的空间
void dfs(int u, int d, int f) //dfs遍历
{
    dfn[++dfncnt] = u, pos[u] = dfncnt, dep[dfncnt] = d;
    for (edge *e = head[u]; e; e = e->next)
        if (e->v != f)
        {
            dfs(e->v, d + 1, u);
            dfn[++dfncnt] = u, dep[dfncnt] = d;
        }
}
void pre(int n) //  lg函数和ST表的预处理
{
    lg[0] = -1;
    for (int i = 1; i < (n << 1); i++)  //  lg函数预处理
        lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i < (n << 1); i++)  //  ST表初始化
        st[0][i] = i;
    for (int i = 1; i <= lg[(n << 1) - 1]; i++)     //  基于倍增(指数倍增)的ST表预处理
        for (int j = 1; j + (1 << i) - 1 < (n << 1); j++)
            st[i][j] = (dep[st[i - 1][j]] < dep[st[i - 1][j + (1 << (i - 1))]]) ? st[i - 1][j] : st[i - 1][j + (1 << (i - 1))];
}
inline int rmq(int u, int v) //查询
{
    int l = pos[u] < pos[v] ? pos[u] : pos[v], r = pos[u] > pos[v] ? pos[u] : pos[v];
    int s = lg[r - l + 1];
    return dep[st[s][l]] < dep[st[s][r - (1 << s) + 1]] ? st[s][l] : st[s][r - (1 << s) + 1];
}

int n, m, A, B, C;

inline void init()
{
    dfs(0, 0, 0);
    pre(n);
}

int main()
{
    // clock_t time1 = clock();
    // freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
    // freopen("2.in", "r", stdin);
	// freopen("2.out", "w", stdout);
    scanf("%d", &n);
    // std::cin >> n;
    for (int i = 1; i < n; i++)         //  读入
    {
        scanf("%d%d", &A, &B);
        // std::cin >> A >> B;
        // int d; std::cin >> d;
        addedge(A, B);
        addedge(B, A);
    }
    // 预处理
    init();
    scanf("%d", &m);
    // std::cin >> m;
    for (int i = 1; i <= m; i++)        //  查询
    {
        scanf("%d%d%d", &A, &B, &C);
        // std::cin >> A >> B >> C;
        int Lab = dfn[rmq(A, B)], Lac = dfn[rmq(A, C)], Lbc = dfn[rmq(B, C)];
        ///*
        if (Lac == C && Lbc == C)       //  情况一
            printf("%s\n", (Lab == C) ? "Yes" : "No");
            // std::cout << (Lab==C)? "Yes\n" : "No\n" ;
        else if (Lac == C || Lbc == C)  //  情况二
            printf("Yes\n");
            // std::cout << "Yes\n";
        else                            //  情况三
            printf("No\n");
            // std::cout << "No\n";
        //*/
    }
	// std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
    // system("pause");
    return 0;
}
