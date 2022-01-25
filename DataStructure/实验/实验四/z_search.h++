/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-12-21 11:29:42
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-12-21 14:13:48
 * @FilePath: \work\DSExperiment\DSE4\z_search.h++
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#pragma once
#include <iostream>
#include <vector>
#include <string>
template <typename _Type>
bool sequential_search(const std::vector<_Type> &arr, const _Type &_find, int &_result, int &cnt)
{
    cnt = 0;
    int _size = arr.size();
    for (int i = 0; i < _size; i++)
    {
        cnt++;
        if (arr[i] == _find)
        {
            _result = i;
            return true;
        }
    }
    _result = _size;
    return false;
}

template <typename _Type>
bool binary_search(const std::vector<_Type> &arr, const _Type &_find, int &_result, int &cnt)
{
    int _size = arr.size();
    int l = 0, r = _size - 1;
    cnt = 0;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (arr[mid] >= _find)
            r = mid;
        else
            l = mid + 1;
        cnt++;
    }
    if (arr[l] == _find)
    {
        _result = l;
        return true;
    }
    else
    {
        _result = _size;
        return false;
    }
}

const int N = 100011;

struct T
{
    int l, r;
    char val;
    T() { l = 0, r = 0, val = '\0'; }
} t_tree[N];

int t_tot;
void insert(int &rt, char val)
{
    if (!rt)
    {
        rt = ++t_tot;
        t_tree[rt].val = val;
        return;
    }
    if (t_tree[rt].val > val)
        insert(t_tree[rt].r, val); //大于当前节点，就往右节点走
    else
        insert(t_tree[rt].l, val); //否则往左节点走
}
void dfs1(int rt)
{
    if (!rt)
        return;
    std::cout << t_tree[rt].val << ' ';
    dfs1(t_tree[rt].l);
    dfs1(t_tree[rt].r);
}
void dfs2(int rt)
{
    if (!rt)
        return;
    dfs2(t_tree[rt].l);
    std::cout << t_tree[rt].val << ' ';
    dfs2(t_tree[rt].r);
}
bool t_find(int rt, char ch, int &num)
{
    if (!rt)
        return 0;
    num++;
    if (t_tree[rt].val == ch)
        return 1;
    if (t_tree[rt].val < ch)
        return t_find(t_tree[rt].l, ch, num);
    else
        return t_find(t_tree[rt].r, ch, num);
}
void BinarySearchTreeTest(std::string s)
{
    int root = 0; //根
    for (int i = 0; i < s.size(); i++)
    {
        insert(root, s[i]);
    }
    std::cout << "The preorder traversal result:\n";
    dfs1(root);
    std::cout << std::endl;
    std::cout << "The inorder traversal result:\n";
    dfs2(root);
    std::cout << std::endl;
    char c;
    while (1)
    {
        std::cout << "Input \"1\" to test or others to end:\n";
        int op;
        std::cin >> op;
        if (op != 1)
            break;
        int t_cnt = 0;
        std::cout << "Input a data to search:\n";
        std::cin >> c;
        if (t_find(root, c, t_cnt))
            std::cout << "Find \"" << c << "\" with comparison times : " << t_cnt << '\n';
        else
            std::cout << "Unable to find \"" << c << "\"\n";
    }
    std::cout << std::endl;
}