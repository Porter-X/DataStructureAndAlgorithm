#include <stdio.h>
#include <string.h>

//calculate the best addition experssion

#define N 10
int numValue[N][N];

int min(int a, int b)
{
    return a < b ? a : b;
}
int main(int argc, char const *argv[])
{
    int m = 2;
    int n = 3;
    char *str = "123";
    n = strlen(str);
    int dp[m + 1][n + 1];

    //calculate all possible number value
    for (int i = 1; i <= n; i++)
    {
        numValue[i][i] = str[i - 1] - '0';//'0'ascii represents 48
        for (int j = i + 1; j <= n; j++)
            numValue[i][j] = numValue[i][j - 1]*10 + str[j - 1] - '0';
    }

    //find the best
    //
    int temp = sizeof(dp);
    memset(dp,0x3f,sizeof(dp));//初始化dp数组，便于对比取最小值
    for (int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
                printf("%x ",dp[i][j]);
            printf("\n");
        }
    for( int i = 1; i <= n; i++)     
        dp[0][i] = numValue[1][i]; 

    for (int i = 1; i <= m; i++) //循环+的个数遍
    {
        for (int j = i; j <= n; j++)//n的个数有子问题1个到原问题n个
        {      
            for (int k = i; k <= j; k++)//k表示+放的位置，i的右边
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + numValue[k + 1][j]);//特别抽象，状态表示很难思考
        }
    }

    for (int i = 1; i < 4; i++)
    {
        for(int j = 1; j < 4; j++)
            printf("%d ",numValue[i][j]);
        printf("\n");
    } 
    printf("\nmin:%d",dp[m][n]);
    return 0;
}
