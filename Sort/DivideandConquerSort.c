#include <stdio.h>

//归并排序算法有两个基本的操作，一个是分，
//也就是把原数组划分成两个子数组的过程。
//另一个是治，它将两个有序数组合并成一个更大的有序数组。
//本文的归并排序我们采用递归去实现（也可采用迭代的方式去实现）。
//分阶段可以理解为就是递归拆分子序列的过程，递归深度为log2n。
/* 算法性能
速度仅次于快速排序。时间复杂度O(nlogn)。空间复杂度O(N)，
归并排序需要一个与原数组相同长度的数组做辅助来排序。 */
int arr[5] = {4,5,3,2,1};
int temp[5];
void Merge(int arr[], int s,int m, int e, int temp[])
{
    int pb = 0;
    int pb1 = s;
    int pb2 = m + 1;
    while (pb1 <= m && pb2 <= e)
    {
        if (arr[pb1] < arr[pb2])
            temp[pb++] = arr[pb1++];
        else
            temp[pb++] = arr[pb2++];
    }
    while (pb1 <= m)
    {
        temp[pb++] = arr[pb1++];
    }
    while (pb2 <= e)
    {
        temp[pb++] = arr[pb2++];
    }
    for (int i = 0; i < e-s+1; i++)
        arr[s + i] = temp[i];

}

void MergeSort(int arr[], int s, int e, int temp[])
{
    if (s < e)
    {
        int mid = s + (e - s)/2; // 相比(e + s)/2
        MergeSort(arr, s, mid, temp);//分
        MergeSort(arr, mid + 1, e, temp);
        Merge(arr, s, mid, e, temp);//治
    }
}
int main(int argc, char const *argv[])
{
    /* code */  
    int size = sizeof (arr)/sizeof(arr[0]);
    MergeSort(arr, 0, size - 1, temp);

    for (int i = 0; i < size; i++)
        printf("%d ",arr[i]);
    return 0;
}
