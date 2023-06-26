#include <stdio.h>
#include <string.h>

#define N 10
int max(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, char const *argv[])
{
    char *str ="what";
    char str1[N]="abce";
    char str2[N]={"abdcefg"};
    int maxLen[N][N];//二维数组保存状态信息
    int length1 = strlen(str1);//sizeof(str1)/sizeof(char) + 1 '\0'== strlen
    int length2 = strlen(str2);
    //maxLen(i,j) s1左边i个字符，s2左边j个字符公共字符
    for (int i = 0; i <= length1; i++)// maxLen 比str多一组向量
        maxLen[i][0] = 0;
    for (int j = 0; j <= length2; j++)
        maxLen[0][j] = 0;

     printf("查看未初始化数组元素的值\n");
    for (int i = 0; i <= length1; i++)//查看未初始化数组元素的值
    {
        for (int j = 0; j <= length2; j++)  
            printf("%d ",maxLen[i][j]);
        printf("\n");
    }
    //循环从头开始每个字符的公共序列
    for (int i = 1; i <= length1; i++)
        for (int j = 1; j <= length2; j++)
            if (str1[i - 1] == str2[j - 1])
                maxLen[i][j] = maxLen[i - 1][j - 1] + 1;
            else
                maxLen[i][j] = max(maxLen[i][j - 1],maxLen[i - 1][j]);
    //printf("length1 : %d length2 : %d sizeof : %d addr : %p",length1,length2,sizeof(str)/sizeof(char),str);

    printf("查看初始化后数组元素的值\n");
    for (int i = 0; i <= length1; i++)//查看初始化后数组元素的值
    {
        for (int j = 0; j <= length2; j++)  
            printf("%d ",maxLen[i][j]);
        printf("\n");
    }
    printf("max:%d",maxLen[length1][length2]);
    return 0;
}
