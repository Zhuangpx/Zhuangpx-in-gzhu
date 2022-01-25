/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2019-12-30 18:54:38
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-12-17 13:14:06
 * @FilePath: \work\DSExperiment\DSE\make.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100005

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int a[N];
int main(int argc, char **argv)
{
    freopen("test.in", "w", stdout);
    int n = 100000;
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
        a[i] = i;
    srand(time(0));
    for (int i = 0; i < n; i++)
        swap(&a[i], &a[rand() % (i + 1)]);
    if (argc == 1 || (*(++argv))[0] == 'r')
        for (int i = 1; i < n; i++)
            printf("%d %d\n", i, a[rand() % i]);
    else
        for (int i = 1; i < n; i++)
            printf("%d %d\n", a[i - 1], a[i]);
    int m = 1000000;
    printf("%d\n", m);
    for (int i = 0; i < m; i++)
        printf("%d %d %d\n", rand() % n, rand() % n, rand() % n);
}