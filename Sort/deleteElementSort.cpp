#include <iostream>

using namespace std;

void BubbleSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                {
                    // swap
                    int temp;
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
        }
    }
}

int main(int argc, char const *argv[])
{
    puts("input the number of elemnts");
    int n;
    int arr[1000];
    cin>>n;
    puts("input number to array");
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    //ШЅжи
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
                {
                    for (int k = j; k < n; k++)
                        {
                            arr[k] = arr[k + 1];
                            n--;
                        }
                }
        }
    }

    BubbleSort(arr, n);
    
    //output
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    return 0;
}
