/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-12-26 23:16:25
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-12-29 10:03:34
 * @FilePath: \work\DSExperiment\DSE\Tarjan.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */
#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <time.h>
#define N 100005
#define M 1000005

typedef struct edge
{
    int v;
    struct edge *next;
} edge;
typedef struct qnode
{
    int v, id;
    struct qnode *next;
} qnode;
edge *head[N], G[N << 1];
qnode *qhead[N], qG[M << 3];
bool vis[N];
int cnt, qcnt, lca[M << 3], p[N];
void addedge(int u, int v) { G[cnt] = (edge){v, head[u]}, head[u] = &G[cnt++]; }
void addq(int u, int v, int id)
{
    qG[qcnt] = (qnode){v, id, qhead[u]}, qhead[u] = &qG[qcnt++];
    qG[qcnt] = (qnode){u, id, qhead[v]}, qhead[v] = &qG[qcnt++];
}

int f(int x) { return (x == p[x]) ? x : (p[x] = f(p[x])); }
void dfs(int u)
{
    p[u] = u;
    vis[u] = 1;
    for (edge *e = head[u]; e; e = e->next)
        if (!vis[e->v])
        {
            dfs(e->v);
            p[e->v] = u;
        }
    for (qnode *q = qhead[u]; q; q = q->next)
        if (vis[q->v])
            lca[q->id] = f(q->v);
}
int A[M], B[M], C[M];
int main()
{
    // clock_t time1 = clock();
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    // freopen("2.in", "r", stdin);
    // freopen("2.out", "w", stdout);
    int n, m, u, v;
    scanf("%d", &n);
    // std::cin >> n;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        // std::cin >> u >> v;
        // int d;  std::cin >> d;
        addedge(u, v);
        addedge(v, u);
    }
    // scanf("%d", &m);
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &A[i], &B[i], &C[i]);
        // std::cin >> A[i] >> B[i] >> C[i];
        addq(A[i], B[i], i * 3);
        addq(A[i], C[i], i * 3 + 1);
        addq(B[i], C[i], i * 3 + 2);
    }
    dfs(0);
    for (int i = 0; i < m; i++)
    {
        int LAB = lca[i * 3], LAC = lca[i * 3 + 1], LBC = lca[i * 3 + 2];
        if (LAB == A[i] && LAC == A[i] && LBC == C[i] || LAB == B[i] && LBC == B[i] && LAC == C[i])
            puts("Yes");
            // std::cout << "YES\n";
        else if (LAC == C[i] && LAB == LBC || LBC == C[i] && LAB == LAC)
            puts("Yes");
            // std::cout << "Yes\n";
        else
            puts("No");
            // std::cout << "No\n";
    }
    // std::cout << "Time:" << clock() - time1 << "ms" << std::endl;
    return 0;
}
