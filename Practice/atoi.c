#include <stdio.h>
#include <stdlib.h>

int custom_atoi(const char* str) {
    int result = 0;
    int sign = 1; // 用于处理正负号

    // 跳过字符串前面的空白字符
    while (*str == ' ' || *str == '\t' || *str == '\n')
        str++;

    // 处理正负号
    if (*str == '-' || *str == '+') {
        sign = (*str == '-') ? -1 : 1;
        str++;
    }

    // 转换字符为整数直到遇到非数字字符
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    // 根据正负号返回最终结果
    return result * sign;
}

 int my_atoi(char *str)
{
    int n = 0;
    int sign = 1;
    //检查正负
    if (*str == '+' || *str == '-')
        sign = (*str == '-')? -1: 1;
    //转换字符为整数知道遇见非数字字符
    while (*str >= '0' && *str <= '9')
    {
        n = n*10 + (*str - '0');
        str++;
    }

    return n*sign;
} 

int main() {
    char str[] = "12a45";
    int num = custom_atoi(str);
    printf("%d\n",atoi("5"));
    printf("%d\n",my_atoi("51"));
    printf("转换后的整数值：%d\n", num);

    return 0;
}
