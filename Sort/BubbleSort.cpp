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

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //int arr[5] = {4,2,1,5,3};
    int arr[5] = {0};
    //���Ӳ��䣬�����Ҳ����
    srand(time(nullptr));//srand(time(nullptr));  �õ�ǰʱ����Ϊ����
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        arr[i] = rand()%100;
    //δ����       
    for (int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    puts("");
    BubbleSort(arr, n);
    //�����
    for (int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    return  0;
}
