/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-12-26 23:16:52
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-12-29 10:05:53
 * @FilePath: \work\DSExperiment\DSE\树链剖分.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#include <stdio.h>
#include <iostream>
#include <time.h>
#define N 100005

typedef struct edge
{
    int v;
    struct edge *next;
} edge;
edge *head[N], G[N << 1];
int siz[N], son[N], dep[N], top[N], fa[N], cnt;
void addedge(int u, int v) { G[cnt] = (edge){v, head[u]}, head[u] = &G[cnt++]; }
void dfs1(int u, int f)
{
    siz[u] = 1, son[u] = -1, fa[u] = f;
    for (edge *e = head[u]; e; e = e->next)
        if (e->v != f)
        {
            dep[e->v] = dep[u] + 1;
            dfs1(e->v, u);
            siz[u] += siz[e->v];
            if (son[u] == -1 || siz[son[u]] < siz[e->v])
                son[u] = e->v;
        }
}
void dfs2(int u, int t)
{
    top[u] = t;
    if (son[u] != -1)
        dfs2(son[u], t);
    for (edge *e = head[u]; e; e = e->next)
        if (e->v != fa[u] && e->v != son[u])
            dfs2(e->v, e->v);
}
int lca(int u, int v)
{
    while (1)
    {
        if (top[u] == top[v])
            return dep[u] > dep[v] ? v : u;
        if (dep[top[u]] > dep[top[v]])
            u = fa[top[u]];
        else
            v = fa[top[v]];
    }
}

int main()
{
    // clock_t time1 = clock();
    // freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
    // freopen("2.in", "r", stdin);
	// freopen("2.out", "w", stdout);
    int n, m, A, B, C;
    scanf("%d", &n);
    // std::cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d%d", &A, &B);
        // std::cin >> A >> B;
        // int d; std::cin >> d;
        addedge(A, B);
        addedge(B, A);
    }
    scanf("%d", &m);
    // std::cin >> m;
    dfs1(0, 0);
    dfs2(0, 0);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &A, &B, &C);
        // std::cin >> A >> B >> C;
        int Lab = lca(A, B), Lac = lca(A, C), Lbc = lca(B, C);
        if (Lac == C && Lbc == C)
            printf("%s\n", (Lab == C) ? "Yes" : "No");
            // std::cout << (Lab==C)? "Yes\n" : "No\n";
        else if (Lac == C || Lbc == C)
            printf("Yes\n");
            // std::cout << "Yes\n";
        else
            printf("No\n");
            // std::cout << "No\n";
    }
	// std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
    return 0;
}