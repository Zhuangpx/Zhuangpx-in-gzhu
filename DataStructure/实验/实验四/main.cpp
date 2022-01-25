/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-12-19 23:52:33
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-12-21 14:43:15
 * @FilePath: \work\DSExperiment\DSE4\main.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include "z_sort.h++"
#include "z_search.h++"
using namespace std;

void sortTest();
void searchTest();

int main()
{
    sortTest();
    searchTest();
}

void sortTest()
{
    srand((unsigned)time(NULL)); //初始化随机化种子
    vector<int> num;             //num数组存储待排序的随机数
    for (int i = 1; i <= 16; i++)
    {
        int temp = rand() % 90 + 10; //获得10~99的随机数
        num.push_back(temp);         //存入数组
    }
    cout << "Init:\n"; //打印原数组
    for (auto i : num)
        cout << i << ' ';
    cout << "\n";
    vector<int> _num = num;         //将数组复制一份
    sort(_num.begin(), _num.end()); //将复制数组排序 作为正确答案的对照
    cout << "After sort:\n";        //打印正确排序的结果
    for (auto i : _num)
        cout << i << ' ';
    cout << "\n";
    vector<int> v = num;
    cout << "InsertionSort:\n"; //插入排序
    InsertionSort(v, true);
    for (auto i : v)
        cout << i << ' ';
    cout << '\n';
    v.clear();
    v = num;
    cout << endl;
    cout << "SelectionSort:\n"; //选择排序
    SelectionSort(v, true);
    for (auto i : v)
        cout << i << ' ';
    cout << '\n';
    v.clear();
    v = num;
    cout << endl;
    cout << "BubbleSort:\n"; //冒泡排序
    BubbleSort(v, true);
    for (auto i : v)
        cout << i << ' ';
    cout << '\n';
    v.clear();
    v = num;
    cout << endl;
    cout << "Twoside_Bubblesort:\n"; //双向冒泡排序
    Twoside_Bubblesort(v, true);
    for (auto i : v)
        cout << i << ' ';
    cout << '\n';
    v.clear();
    v = num;
    cout << endl;
    cout << "QuickSort:\n"; //快速排序
    QuickSort(v, 0, 15, true);
    for (auto i : v)
        cout << i << ' ';
    cout << '\n';
    v.clear();
    v = num;
    cout << endl;
    cout << "MergeSort:\n";
    MergeSort(v, 0, 15, true);
    for (auto i : v)
        cout << i << ' ';
    cout << '\n';
    v.clear();
    v = num;
}

void searchTest()
{
    srand((unsigned)time(NULL)); //初始化随机化种子
    vector<char> data;           //num数组存储待排序的随机数
    for (int i = 1; i <= 16; i++)
    {
        int temp = rand() % 16;             //获得0~15的随机数
        data.push_back((char)(temp + 'a')); //存入数组
    }
    cout << "Init:\n"; //打印原数组
    for (auto i : data)
        cout << i << ' ';
    cout << "\n";
    cout << "Sequential search:\n";
    while (1)
    {
        cout << "Input \"1\" to test or others to end:\n";
        int op;
        cin >> op;
        if (op != 1)
            break;
        cout << "Input a data to search:\n";
        char c;
        cin >> c;
        int cnt = 0;
        int result = 0;
        bool flag = sequential_search(data, c, result, cnt);
        if (!flag)
        {
            cout << "Unable to find \"" << c << "\"\n";
        }
        else
        {
            cout << "Find \"" << c << "\" at the subscript of \"" << result << "\" ,with comparison times : " << cnt << '\n';
        }
    }
    cout << endl;
    cout << "Binary search:\n";
    sort(data.begin(), data.end());
    cout << "After sort:\n"; //排序
    for (auto i : data)
        cout << i << ' ';
    cout << "\n";
    while (1)
    {
        cout << "Input \"1\" to test or others to end:\n";
        int op;
        cin >> op;
        if (op != 1)
            break;
        cout << "Input a data to search:\n";
        char c;
        cin >> c;
        int cnt = 0;
        int result = 0;
        bool flag = binary_search(data, c, result, cnt);
        if (!flag)
        {
            cout << "Unable to find \"" << c << "\"\n";
        }
        else
        {
            cout << "Find \"" << c << "\" at the subscript of \"" << result << "\" ,with comparison times : " << cnt << '\n';
        }
    }
    cout<<endl;
    cout<<"Search by Binary Search Tree :\n";
    cout<<"Input the init string\n";
    string s;
    cin>>s;
    BinarySearchTreeTest(s);
}
