#include <stdio.h>
#include <stdbool.h>

char str[100];
char str[100];
bool isPalindrome(int x){
    bool ret = 1;
    sprintf(str,"%d",x);//������ת��Ϊ�ַ���
   
    unsigned char length = strlen(str);
    printf("length:%d",length);
    char *L,*R;//����˫ָ��
    L = &str;
    R = &str[length-1];
    while (L < R)
    {
        if (*L != *R)
           {
               ret = 0;
               break;
           } 
        L++;
        R--;
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    printf("Ret = %d\n",isPalindrome(121));

    return 0;
}
