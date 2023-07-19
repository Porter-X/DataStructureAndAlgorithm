#include <iostream>
#include <string.h>

using namespace std;

void sortStr(char **str, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (*str[j] > *str[j + 1])
            {
                char *temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    char **str;
    str = (char**)malloc(n*sizeof(char*));

    for (int i = 0; i < n; i++)
    {

      char buff[100];
      cin>>buff;
      str[i] = (char *)malloc((strlen(buff) + 1) * sizeof(char));
      strcpy(str[i],buff);

    }

    sortStr(str, n);
    
    for (int i = 0; i < n; i++)
        puts(str[i]);
    return 0;
}













/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortStrings(char** strings, int n) {
    char* temp;
    
    // 使用冒泡排序对字符串进行排序
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(strings[j], strings[j+1]) > 0) {
                // 交换两个字符串的位置
                temp = strings[j];
                strings[j] = strings[j+1];
                strings[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    
    printf("请输入字符串的个数：");
    scanf("%d", &n);
    
    // 创建字符串数组
    char** strings = (char**)malloc(n * sizeof(char*));
    
    // 读取每个字符串
    for (int i = 0; i < n; i++) {
        printf("请输入第 %d 个字符串：", i+1);
        char buffer[100];
        scanf("%s", buffer);
        
        // 分配内存并复制字符串
        strings[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(strings[i], buffer);
    }
    
    // 按字典顺序排序字符串
    sortStrings(strings, n);
    
    printf("按字典顺序排序后的字符串：\n");
    
    // 输出排序后的字符串
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }
    
    // 释放内存
    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);
    
    return 0;
} */