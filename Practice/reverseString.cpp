#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    char  arr[1000];
    gets(arr);

    int len = strlen(arr);
    for (int i = len - 1; i >=0; i--)
        putchar(arr[i]);
    
    return 0;
} 



