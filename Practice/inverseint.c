#include <stdio.h>
#include <stdlib.h>

int reverse(int x){
    int result = 0;
    int n =  -pow(2,31);
    printf ("pow(2,31)  :%d\n", n);
    while ( x != 0)
    {
        if (result > INT_MAX/ 10 || result < INT_MIN/ 10)
            return 0;
        result = result * 10 + x % 10;
        x /= 10;
        printf ("test point :%d\n", result);
    }

    return result ;
}

int main(int argc, char const *argv[])
{
    int i = 2147483647;//7463847412;// 2147483647
    printf("%d",reverse(i));
    return 0;
}
