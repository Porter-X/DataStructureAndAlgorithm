#include <iostream>
#include <string.h>

using namespace std;

// µ¥¸ö×Ö·û×ª»»
/* int main(int argc, char const *argv[])
{

    char ch;

    while (scanf("%c",&ch) != EOF)
    {
        if (ch <= '9')
        {
            putchar(ch);
        }
        else if (ch <= 'F')
        {
            putchar('1');
            char c = ch - 'A';
            putchar(c + 48);//'0' == 48
        }
        else
        {
            puts("worng input");
        }
    }
    return 0;
}  */

int main(int argc, char const *argv[])
{
    char arr[5];
    int num = 0;
    gets(arr);

    for (int i = 0; i < strlen(arr); i++)
    {
        if (arr[i] > '0' && arr[i] < '9')
            num = num * 16 + arr[i] - '0';
        else
            num = num * 16 + arr[i] - 'A' + 10;
    }

    cout <<num<<endl;

    return 0;
}
