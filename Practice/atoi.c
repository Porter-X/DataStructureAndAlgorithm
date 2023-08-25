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


int myAtoi(char * s){
    char * p = s;
    int pOrn = 1;//正
    int num = 0;
    while (*p == ' ')
    {
        p++;
    }
    //putchar(*p);
    if (*p == '-' || *p == '+')
    {
        pOrn = (*p == '-') ? -1 : 1;//简洁的三目运算
        p++;
    }

    if (*p < '0' || *p > '9')
    {
        return 0;//不满足要求直接返回
    }
    while (*p >= '0' && *p <= '9')
    {
        if ( num > INT_MAX / 10 ||  (num == INT_MAX / 10 && (*p - '0') > INT_MAX % 10)) //当前num大于最大值的十分之一直接返回，
                                                                                 
        { //或者num == 最大值的十分之一并且加上下一个字符会越界
            if (pOrn == -1)
                return INT_MIN;
            else
                return INT_MAX;
        }   
        num = num * 10 + (*p - '0');

        //printf("num :%d\n", num);
        p++;
    }
    printf("max :%d\n", INT_MAX);
    printf("min :%d\n",INT_MIN);
    printf("num :%d\n", INT_MAX % 10);
    return num * pOrn;
}

int main() {
    char str[] = "12a45";
    int num = custom_atoi(str);
    printf("%d\n",atoi("5"));
    printf("%d\n",my_atoi("51"));
    printf("转换后的整数值：%d\n", num);

    return 0;
}
