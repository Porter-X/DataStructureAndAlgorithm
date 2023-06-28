#include <iostream>
using namespace std;

int visited[30][50];

//有多少种走法
int ways(int i, int j, int n)//函数带返回值
{
    if (n ==0)//基于步数递归退出的条件
        return 1;
    int num = 0;
    visited[i][j] = 1;
    if (visited[i + 1][j] == 0) 
        num += ways(i + 1, j,n - 1); 
    if (visited[i][j + 1] == 0) 
        num += ways(i, j + 1,n - 1);    
    if (visited[i][j - 1] == 0) 
        num += ways(i, j - 1,n - 1);
    visited[i][j] = 0;

    return num;                
}

int main(int argc, char const *argv[])
{
    int n = 2;
    cout<<ways(0, 25, n);
    return 0;
}
