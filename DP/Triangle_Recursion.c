#include <stdio.h>

#define N 4
int triangle[N][N]={{0},{0,1},{0,2,3},{0,4,5,6}};//,{7,8,9,10}
int maxSum[N][N];

int  max (int a, int b)
{
    return a > b? a:b;
}

int MaxSum(int row, int column)
{
    if(maxSum[row][column] != -1)
        return maxSum[row][column];
    if (row == N)
        return triangle[row][column];
    
    int x = MaxSum(row + 1, column);
    int y = MaxSum(row + 1, column + 1);
    maxSum[row][column] = max(x,y) + triangle[row][column];
    return max (x,y) + triangle[row][column];
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N ; j++)
            printf("%d ",triangle[i][j]);
        printf("\n");
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N ; j++)
            {
                maxSum[i][j] = -1;
                printf("%d ",maxSum[i][j]);
            }
            
        printf("\n");
    }
    int result = MaxSum(1,1);
    printf("%d ",result);

    return 0;
}

