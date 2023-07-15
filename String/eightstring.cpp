#include <iostream>
#include <string.h>

using namespace std;

#define N 10

int main(int argc, char const *argv[])
{
    char arr1[N] = {0};
    char arr2[N] = {0};
    int len1, len2;
    gets(arr1);
    gets(arr2);

    len1 = strlen(arr1);
    len2 = strlen(arr2);
    int shift = len1;
    while (len1 > 8)
    {
        for (int i = 0; i < 8; i++)
            putchar(arr1[i]);
        len1 -= 8;
    }

    while ((len1 = strlen(arr1) )< 8)
    {
        arr1[len1] = '0';

    }
   // arr1[len1 + 1] = '\0';
    puts(arr1);
    return 0;
}
