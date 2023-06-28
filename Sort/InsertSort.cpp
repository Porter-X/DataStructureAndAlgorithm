#include <iostream>
using namespace std;

#define N 5
void InsertionSort(int arr[],int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)//foreach every elements
    {
        key = arr[i];
/*         j = i - 1;
        while (j >= 0 && arr[j] > key)//compare and insert
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; */
        for(j = i - 1; j >= 0 && arr[j] > key; j--)//从尾部开始比较
        {
            arr[j+1] = arr[j];
        }
        arr[j + 1] = key;
    }
}
void InsertSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
        {
            int temp = arr[i];
           for(int j = 0; j < i; j++)//从头开始比较
            {
                if (temp < arr[j])
                {
                    for (int k = i; k > j; k--)// insert
                    {   
                        arr[k] = arr [k - 1];
                    }
                    arr[j] = temp;
                }
            }
        }
}
int main(int argc, char const *argv[])
{
    int array[N] = {5,3,2,1,4};
    int n = sizeof(array)/sizeof(array[0]);

    InsertionSort(array, n);
    for (int i = 0; i < N; ++i)
        cout<<array[i]<<" ";
    return 0;
}
