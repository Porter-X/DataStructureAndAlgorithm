#include <stdio.h>
#include <stdbool.h>

char str[100];
char str[100];
bool isPalindrome(int x){
    bool ret = 1;
    sprintf(str,"%d",x);//将整数转换为字符串
   
    unsigned char length = strlen(str);
    printf("length:%d",length);
    char *L,*R;//定义双指针
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
