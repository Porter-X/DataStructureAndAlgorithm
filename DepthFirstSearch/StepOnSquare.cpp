#include <iostream>
using namespace std;

int visited[30][50];

//�ж������߷�
int ways(int i, int j, int n)//����������ֵ
{
    if (n ==0)//���ڲ����ݹ��˳�������
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