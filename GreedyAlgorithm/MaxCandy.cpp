#include <iostream>
using namespace std;

struct Candy{
    int value;
    int weight;
    int average;
};

void InsertSort(struct Candy arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        struct Candy key = arr[i];
        int j;
        for ( j = i - 1; j >= 0 && arr[j].average < key.average; j--)
        {
            arr[j + 1] = arr[j];
        }
         arr[j + 1] = key;
    }
}

int main(int argc, char const *argv[])
{
    int n = 4;
    int weight = 15;
    int totalW = 0;
    int sumValue = 0;
    int data[4][2]={{100,4},{412,8},{266,7},{591,2}};//数据
    Candy candies[n];
    for (int i = 0; i < n; i++)//初始化结构体数组
        {
            candies[i].value = data[i][0];
            candies[i].weight = data[i][1];
            candies[i].average = candies[i].value/candies[i].weight;
        }
    InsertSort(candies, n);    
    cout<< "sort"<<endl; 
        for (int i = 0; i < n; i++)
        {
        cout<<"candies[i].value :" <<candies[i].value<<endl ;
        cout<<"candies[i].weight :"<<candies[i].weight<<endl ;
        cout<<"candies[i].average :" <<candies[i].average<<endl ;
        }
        //装糖果
        for (int i = 0; i < n; i++)
        {
            if (weight - totalW >= candies[i].weight)
                {
                    totalW += candies[i].weight;
                    sumValue += candies[i].value;
                }
            else
            {
                sumValue += candies[i].average * (weight - totalW);
                totalW +=(weight - totalW);
                break;
            }

        }
        cout<<"sumValue:"<<sumValue<<endl;
    return 0;
}
