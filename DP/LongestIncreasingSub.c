#include <stdio.h>

#define N 6
int max(int a, int b)
{
    return a > b ? a : b;
}

int maxElement(int arr[], int n) //找出数组中的最大元素
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp)
            temp = arr[i];
    }
    return temp;
}

int main(int argc, char const *argv[])
{
    int array[N] = {0,1,2,3,2,5};
    int maxLen[N];
    for (int i = 0; i < N; i++)//数组初始化
    {
        maxLen[i] = 1;
        printf("%d ",maxLen[i]);
    }

    for (int i = 2; i < N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (array[i] > array[j])
                maxLen[i] = max(maxLen[i],maxLen[j] + 1);//递推公式
        }
    }
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ",maxLen[i]);
    }
    printf("\nlongest increasing subsequence:%d ",maxElement(maxLen + 1, N));

    return 0;
}
