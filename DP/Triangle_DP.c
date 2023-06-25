#include <stdio.h>

#define N 4
int triangle[N][N]={{0},{0,1},{0,2,3},{0,4,5,6}};//,{7,8,9,10}
int maxSum[N][N];

int  max (int a, int b)
{
    return a > b? a:b;
}




//µ›Õ∆¡Ω≤„—≠ª∑
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
                //printf("%d ",maxSum[i][j]);
            }
            
        printf("\n");
    }

    for (int i = 1; i < N; ++i)
    {
        maxSum[N-1][i] = triangle[N-1][i];
    }
  
    for (int i = N - 2; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
            maxSum[i][j] = max(maxSum[i + 1][j],maxSum[i + 1][j + 1]) + triangle[i][j]; 
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N ; j++)
            {
                printf("%d ",maxSum[i][j]);
            }
            
        printf("\n");
    } 
    printf("%d ",maxSum[1][1]);

    return 0;
}

