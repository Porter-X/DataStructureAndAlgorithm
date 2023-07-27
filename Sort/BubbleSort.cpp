#include <iostream>
#include <random>
#include <time.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int *arr, int n)
{

    for (int i = 0; i < n - 1; i++)//每循环一次将最小值放开头
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
        }
    }
}

void BubbleSort2(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)//循环一次最大值放最后
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void BubbleSort3(int *arr, int n)
{
    //升序
    for (int i = 0; i < n - 1; i++)//每循环一个i 最大值放最后
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //int arr[5] = {4,2,1,5,3};
    int arr[5] = {0};
    //种子不变，随机数也不变
    srand(time(nullptr));//srand(time(nullptr));  用当前时间作为种子
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        arr[i] = rand()%100;
    //未排序       
    for (int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    puts("");
    BubbleSort3(arr, n);
    //排序后
    for (int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    return  0;
}
