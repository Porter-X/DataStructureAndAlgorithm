#include <iostream>
#include <string.h>

//my method
/* int main(int argc, char const *argv[])
{
    char str[100];
    gets(str);

    int len = strlen(str);
    int flag = len;
    while (len >= 0)
    {

        while (str[flag] != ' ' && flag != -1) //以空格为标记
            flag--;
       for (int i = flag + 1; i < len; i++)//逐个打印单词
       {
            putchar(str[i]);
       }
       if (flag != -1)//最后一个单词不需要打印空格
        putchar(' ');
       len = flag;
       flag--;
    }
    return 0;
} */
void reverse(char *str, int s, int e)
{
    while (s < e)
    {
        char temp = str[s];
        str[s] = str[e];
        str[e] = temp;
        s++;
        e--;    
    }

}

int main(int argc, char const *argv[])
{
     int s = 0;
    int flag = 0;
    char str[100];
    gets(str);

    int len = strlen(str);

    reverse(str, 0, len-1);


    while ( str[flag] != '\0')
    {
        while (str[flag]  != ' ' && str[flag] != '\0')
            flag++;
        reverse(str, s, flag - 1);
        s = flag + 1;   
        flag++; 
    }    

    puts(str);

    return 0;
}
