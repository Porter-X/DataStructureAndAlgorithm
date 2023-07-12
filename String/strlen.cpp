#include <iostream>
#include <string.h>
using namespace std;

int mystrlen(char *string)
{
    int cnt = 0;
    while(*string )
      {
        cnt++;
        string++;
      }  
    return cnt;
}

void fit(char *string, unsigned int size)
{
    if (strlen(string) > size)
        string[size] = '\0';
    
}

int main(int argc, char const *argv[])
{
    char arr[] = "abcd";

    cout<<mystrlen(arr)<<"sizeof:"<<sizeof(arr)/sizeof(arr[0])<<endl;
    puts(arr);
    fit(arr, 3);
    puts(arr);
    //需要指定流的方向
    //putc(arr[0],stdout);
    //fputc(arr[0],stdout);
    //默认是stdout
    putchar(arr[0]);
    return 0;
}
