#include "stdio.h"

int fatorial(int i)
{
    if(i==0)
        return 1;
    else
        return i*fatorial(i-1);
}
int main(int argc, char const *argv[])
{
    int n;
    n=5;
    n=fatorial(n);
    printf("%d\n",n);
    return 0;
}
