#include <iostream>
#include <string.h>

using namespace std;

#define N 100

int main(int argc, char const *argv[])
{
    char arr1[N] = {0};
    char arr2[N] = {0};
    char * p;
    int len1, len2;
    gets(arr1);
  //  gets(arr2);


    len1 = strlen(arr1);
    p = arr1;
 //   putchar(*p++);
    while (len1 > 8)
    {
        for (int i = 0; i < 8; i++)
            putchar(p[i]);
        len1 -= 8;
        p = p + 8;
        puts("");
    }

    while ((len1 = strlen(p) )< 8)
    {
        p[len1] = '0';
    }
   // arr1[len1 + 1] = '\0';
   puts(p);
    return 0;
}
