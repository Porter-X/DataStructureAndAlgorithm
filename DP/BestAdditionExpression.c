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
    memset(dp,0x3f,sizeof(dp));//��ʼ��dp���飬���ڶԱ�ȡ��Сֵ
    for (int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
                printf("%x ",dp[i][j]);
            printf("\n");
        }
    for( int i = 1; i <= n; i++)     
        dp[0][i] = numValue[1][i]; 

    for (int i = 1; i <= m; i++) //ѭ��+�ĸ�����
    {
        for (int j = i; j <= n; j++)//n�ĸ�����������1����ԭ����n��
        {      
            for (int k = i; k <= j; k++)//k��ʾ+�ŵ�λ�ã�i���ұ�
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + numValue[k + 1][j]);//�ر����״̬��ʾ����˼��
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
