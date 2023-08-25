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


int myAtoi(char * s){
    char * p = s;
    int pOrn = 1;//��
    int num = 0;
    while (*p == ' ')
    {
        p++;
    }
    //putchar(*p);
    if (*p == '-' || *p == '+')
    {
        pOrn = (*p == '-') ? -1 : 1;//������Ŀ����
        p++;
    }

    if (*p < '0' || *p > '9')
    {
        return 0;//������Ҫ��ֱ�ӷ���
    }
    while (*p >= '0' && *p <= '9')
    {
        if ( num > INT_MAX / 10 ||  (num == INT_MAX / 10 && (*p - '0') > INT_MAX % 10)) //��ǰnum�������ֵ��ʮ��֮һֱ�ӷ��أ�
                                                                                 
        { //����num == ���ֵ��ʮ��֮һ���Ҽ�����һ���ַ���Խ��
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
    printf("ת���������ֵ��%d\n", num);

    return 0;
}
