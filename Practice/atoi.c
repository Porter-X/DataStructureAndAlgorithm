#include <stdio.h>
#include <stdlib.h>

int custom_atoi(const char* str) {
    int result = 0;
    int sign = 1; // ���ڴ���������

    // �����ַ���ǰ��Ŀհ��ַ�
    while (*str == ' ' || *str == '\t' || *str == '\n')
        str++;

    // ����������
    if (*str == '-' || *str == '+') {
        sign = (*str == '-') ? -1 : 1;
        str++;
    }

    // ת���ַ�Ϊ����ֱ�������������ַ�
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    // ���������ŷ������ս��
    return result * sign;
}

 int my_atoi(char *str)
{
    int n = 0;
    int sign = 1;
    //�������
    if (*str == '+' || *str == '-')
        sign = (*str == '-')? -1: 1;
    //ת���ַ�Ϊ����֪�������������ַ�
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
    printf("ת���������ֵ��%d\n", num);

    return 0;
}
