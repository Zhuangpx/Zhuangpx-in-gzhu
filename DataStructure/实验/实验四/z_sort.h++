/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-12-20 16:52:32
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-12-21 14:53:41
 * @FilePath: \work\DSExperiment\DSE4\z_sort.h++
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */
#pragma once
#include <iostream>
#include <vector>

// 失败 出现未知错误
template <typename _Type>
inline void z_swap(_Type &x,_Type &y)
{
    _Type tmp=x;
    x=y;
    y=x;
}

//此函数用于打印数组
template <typename _Type>
void show_arr(const std::vector<_Type> &arr)
{
    for (auto i : arr)
        std::cout << i << ' ';
    std::cout << std::endl;
}

//插入排序
template <typename _Type>
void InsertionSort(std::vector<_Type> &arr, bool _show = false)
{
    int _size = arr.size();
    int process_count = 1;          //第n次中间过程
    int compare_count = 0;          //关键字比较次数
    int remove_count = 0;           //关键字移动次数
    for (int i = 1; i < _size; i++) //遍历未排序的元素
    {
        int _pos = i - 1;
        int _now = arr[i];
        while (++compare_count && _pos >= 0 && arr[_pos] > _now) //倒着遍历已排序的元素 比当前元素大则往后移一位
        {
            remove_count++;
            arr[_pos + 1] = arr[_pos];
            _pos--;
        }
        remove_count++;
        arr[_pos + 1] = _now; //  将找出的元素插入
        if (_show)
        {
            std::cout << "Show the " << process_count++ << "th intermediate process:\n";
            show_arr(arr);
        }
    }
    if (_show)
    {
        std::cout << "Show the " << process_count++ << "th intermediate process:\n";
        show_arr(arr);
        std::cout << "Keyword comparison times : " << compare_count << '\n';
        std::cout << "Keyword movement times : " << remove_count << '\n';
        std::cout << std::endl;
    }
}

//选择排序
template <typename _Type>
void SelectionSort(std::vector<_Type> &arr, bool _show = false)
{
    int _size = arr.size();
    int process_count = 1; //第n次中间过程
    int compare_count = 0; //关键字比较次数
    int remove_count = 0;  //关键字移动次数
    for (int i = 0; i < _size - 1; i++)
    {
        int _pos = i;
        for (int j = i + 1; j < _size; j++) //找出第i小元素
        {
            compare_count++;
            if (arr[_pos] > arr[j])
                _pos = j;
        }
        remove_count++;
        // z_swap(arr[_pos], arr[i]); //将找出的元素置至第i位置
        _Type tmp = arr[_pos];
        arr[_pos] = arr[i];
        arr[i] = tmp;
        //  swap
        if (_show)
        {
            std::cout << "Show the " << process_count++ << "th intermediate process:\n";
            show_arr(arr);
        }
    }
    if (_show)
    {
        std::cout << "Show the " << process_count++ << "th intermediate process:\n";
        show_arr(arr);
        std::cout << "Keyword comparison times : " << compare_count << '\n';
        std::cout << "Keyword movement times : " << remove_count << '\n';
        std::cout << std::endl;
    }
}

//冒泡排序
template <typename _Type>
void BubbleSort(std::vector<_Type> &arr, bool _show = false)
{
    int _size = arr.size();
    int process_count = 1;               //第n次中间过程
    int compare_count = 0;               //关键字比较次数
    int remove_count = 0;                //关键字移动次数
    for (int i = _size - 1; i >= 1; i--) //进行_size-1次相邻交换 每次交换后末尾元素一定是最大的 也就是从后往前数第i个元素置位
    {
        for (int j = 0; j < i; j++)
        {
            compare_count++;
            if (arr[j] > arr[j + 1])
            {
                // z_swap(arr[j], arr[j + 1])；
                _Type tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                //  swap
                remove_count++;
            }
        }
        if (_show)
        {
            std::cout << "Show the " << process_count++ << "th intermediate process:\n";
            show_arr(arr);
        }
    }
    if (_show)
    {
        std::cout << "Show the " << process_count++ << "th intermediate process:\n";
        show_arr(arr);
        std::cout << "Keyword comparison times : " << compare_count << '\n';
        std::cout << "Keyword movement times : " << remove_count << '\n';
        std::cout << std::endl;
    }
}

//双向冒泡排序
template <typename _Type>
void Twoside_Bubblesort(std::vector<_Type> &arr, bool _show = false)
{
    int _size = arr.size();
    int process_count = 1;                          //第n次中间过程
    int compare_count = 0;                          //关键字比较次数
    int remove_count = 0;                           //关键字移动次数
    for (int l = 0, r = _size - 1; l < r; l++, r--) //l左端 r右端 每次交换操作会找出当前最小和最大即第l小和第r小并置位置l和r 同时l和r向中间收缩
    {
        //当前区间[l,r] 此时[0,l)和(r,n-1]已置位
        for (int i = l; i < r; i++) //置当前最大元素至位置r
        {
            compare_count++;
            if (arr[i] > arr[i + 1])
            {
                // z_swap(arr[i], arr[i + 1]);
                _Type tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                //  swap
                remove_count++;
            }
        }
        for (int i = r; i > l; i--) //置当前最小元素至位置l
        {
            compare_count++;
            if (arr[i] < arr[i - 1])
            {
                // z_swap(arr[i], arr[i - 1]);
                _Type tmp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = tmp;
                //  swap
                remove_count++;
            }
        }
        if (_show)
        {
            std::cout << "Show the " << process_count++ << "th intermediate process:\n";
            show_arr(arr);
        }
    }
    if (_show)
    {
        std::cout << "Show the " << process_count++ << "th intermediate process:\n";
        show_arr(arr);
        std::cout << "Keyword comparison times : " << compare_count << '\n';
        std::cout << "Keyword movement times : " << remove_count << '\n';
        std::cout << std::endl;
    }
}

//快速排序(分区交换排序) Quick sort Or Partition-exchange sort
/*
    快速排序基于分治的思想，具体来说就是对一个数组选一个基准值arr[base](通常以最后一个)，然后将比它小的置于它的左边，比它大的置于它的右边
    此时base成功置位，接下来递归处理base左区间和右区间的子数组。
    每次能确定一个位置的元素，递归结束后即可完成排序。
*/

template <typename _Type>
void _QuickSort(std::vector<_Type> &arr, int l, int r, int _size, int &process_count, int &compare_count, int &remove_count, bool _show = false)
{
    //递归处理当前区间[l,r] 默认基准值为arr[r] 即base=r
    if (l >= r)
        return;                 //区间大小小于等于1时退出
    int _cnt = l;               //比基准值arr[base]小的元素个数 交换时比基准值小的应该置到cnt位置
    for (int i = l; i < r; i++) //遍历比较[l,r)
    {
        compare_count++;
        if (arr[i] < arr[r])
        {
            remove_count++;
            // z_swap(arr[i], arr[_cnt]); //比基准值小放在左边
            _Type tmp = arr[i];
            arr[i] = arr[_cnt];
            arr[_cnt] = tmp;
            //  swap
            _cnt++;
        }
    }
    //遍历交换后[l,cnt)区间的数比基准值小 并且位置cnt的元素大于等于基准值
    //再置位置cnt为基准值 此时[l,cnt-1]区间比基准值小 [cnt+1,r]区间比基准值大
    // z_swap(arr[_cnt], arr[r]);
    _Type tmp = arr[_cnt];
    arr[_cnt] = arr[r];
    arr[r] = tmp;
    //  swap
    remove_count++;
    //递归区间[l,cnt-1]
    _QuickSort(arr, l, _cnt - 1, _size, process_count, compare_count, remove_count, _show);
    //递归区间[cnt+1,r]
    _QuickSort(arr, _cnt + 1, r, _size, process_count, compare_count, remove_count, _show);
    if (_show)
    {

        std::cout << "Show the " << process_count++ << "th intermediate process:\n";
        show_arr(arr);
    }
}

template <typename _Type>
void QuickSort(std::vector<_Type> &arr, int l, int r, bool _show = false)
{
    int _size = arr.size();
    int process_count = 1; //第n次中间过程
    int compare_count = 0; //关键字比较次数
    int remove_count = 0;  //关键字移动次数
    _QuickSort(arr, l, r, _size, process_count, compare_count, remove_count, _show);
    if (_show)
    {
        // std::cout << "Show the " << process_count++ << "th intermediate process:\n";
        // show_arr(_arr);
        std::cout << "Keyword comparison times : " << compare_count << '\n';
        std::cout << "Keyword movement times : " << remove_count << '\n';
        std::cout << std::endl;
    }
}

//(二路)归并排序
/*
    二路归并排序具体来说就是把当前数组一分为二，然后分别对两个数组排序
    之后把两个有序的数组进行合并，此时整个数组便是有序的
    两个子数组也是同样方法，因此可以递归地拆开，排序，再归并。
    考虑如何合并两个有序数组
    每次从左右两个区间取出最小的 那么当前区间最小的就是其中之一 由于两个区间有序 因此主要取首个元素
    设置一个临时数组 不断取出最小元素 当某个区间结束另一个区间有剩余 需要把剩余元素依次复制
    结束后临时数组即为当前区间排序结果
*/
//归并排序合并操作函数
template <typename _Type>
void Merge(std::vector<_Type> &arr, int l, int mid, int r, int &process_count, int &compare_count, int &remove_count, bool _show = false)
{
    int i = l, j = mid + 1, _pos = 0;
    std::vector<_Type> _tmp(r - l + 1); //临时存储当前区间
    while (i <= mid && j <= r)          //每次取出两个区间的第一个元素 最小的那个就是整个区间最小的元素 因此二者取一得到当前最小元素
    {
        compare_count++;
        remove_count++;
        if (arr[i] > arr[j])
            _tmp[_pos++] = arr[j++];
        else
            _tmp[_pos++] = arr[i++];
    }
    //  如果其中一个区间还有剩余 需要继续复制
    while (i <= mid)
        _tmp[_pos++] = arr[i++], remove_count++;
    while (j <= r)
        _tmp[_pos++] = arr[j++], remove_count++;
    //  结束后此时_tmp数组为当前区间排完序后的结果 重新复制指arr的区间[l,r]内
    for (int _i = l, _j = 0; _i <= r; _i++, _j++)
    {
        arr[_i] = _tmp[_j];
        remove_count++;
    }
}
//归并排序递归函数
template <typename _Type>
void _MergeSort(std::vector<_Type> &arr, int l, int r, int &process_count, int &compare_count, int &remove_count, bool _show = false)
{
    /*  对区间[l,r]归并排序
        先分成[l,mid]和[mid+1,r]两个区间递归地排序 再对两个有序区间进行合并
    */
    if (l >= r)
        return;
    int mid = (l + r) / 2;                                                          //取中间
    _MergeSort(arr, l, mid, process_count, compare_count, remove_count, _show);     //左区间
    _MergeSort(arr, mid + 1, r, process_count, compare_count, remove_count, _show); //右区间
    Merge(arr, l, mid, r, process_count, compare_count, remove_count, _show);       //合并操作
    if (_show)
    {

        std::cout << "Show the " << process_count++ << "th intermediate process:\n";
        show_arr(arr);
    }
}
//归并排序主函数
template <typename _Type>
void MergeSort(std::vector<_Type> &arr, int l, int r, bool _show = false)
{
    int _size = arr.size();
    int process_count = 1; //第n次中间过程
    int compare_count = 0; //关键字比较次数
    int remove_count = 0;  //关键字移动次数
    //开始排序
    _MergeSort(arr, l, r, process_count, compare_count, remove_count, _show);
    if (_show)
    {
        // std::cout << "Show the " << process_count++ << "th intermediate process:\n";
        // show_arr(_arr);
        std::cout << "Keyword comparison times : " << compare_count << '\n';
        std::cout << "Keyword movement times : " << remove_count << '\n';
        std::cout << std::endl;
    }
}