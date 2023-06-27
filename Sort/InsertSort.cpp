#include <iostream>
using namespace std;

#define N 5
void InsertSort(int arr[], int n)
{
    for (int i = 1; i <= n; ++i)
        {
           for(int j = 0; j < i; j++)
            if (arr[i] < arr[j])
                {
                    for (int k = j; k < i - j; k++)
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
        }
}
int main(int argc, char const *argv[])
{
    int array[N] = {5,3,2,1,4};
    int n = sizeof(array)/sizeof(array[0]);

    InsertSort(array, n);
    for (int i = 0; i < N; ++i)
        cout<<array[i]<<" ";
    return 0;
}
