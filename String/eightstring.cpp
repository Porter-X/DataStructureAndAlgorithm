#include <iostream>
#include <string.h>

using namespace std;

#define N 100
/* 
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
        len1 -= 8;//³¤¶ÈÆ«ÒÆ
        p = p + 8;//Ö¸ÕëÆ«ÒÆ
        puts("");
    }

    while ((len1 = strlen(p) )< 8)
    {
        p[len1] = '0';//²¹Áã
    }
   // arr1[len1 + 1] = '\0';
   puts(p);
    return 0;
} */

int main(int argc, char const *argv[])
{
    char arr1[N];
    char *p = arr1;
    int cnt = 0;
    gets(arr1);

    while (*p != '\0')
    {
        putchar(*p++);
        if (++cnt == 8)
        {
            cnt = 0;
            puts("");
        }

    }

/*     while (*p == '\0' && cnt != 0)
    {
        putchar('0');
        cnt++;
        if (cnt == 8)
            break;
    } */
    if (*p == '\0' && cnt != 0 )
    {
        while (cnt++ != 8)
            putchar('0');
    }


    return 0;
}
