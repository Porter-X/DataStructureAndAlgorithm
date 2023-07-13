#include <iostream>
#include <string.h>

using namespace std;

#define N 5000

void my_method(void)
{
    char string[N];
    int i = 0, cnt = 0;
    fgets(string, N, stdin);

    puts(string);

    while (string[i] != '\0')
    {
        cnt++;
        if(string[i] == ' ')
            cnt = 0;
        i++;

    }
    cout<<"length = "<<cnt - 1<<endl;//-1  '\n'¼õÈ¥»»ÐÐ·û
}

int main(int argc, char const *argv[])
{
    //my_method();
    int len = 0;
    char string[5000];

    gets(string);//gets has no '\n'
    //fgets(string, N, stdin);//fgets has '\n'
    for (int i = strlen(string) - 1 ; i >= 0 && string[i] != ' '; i--)//i count from 0
        len++;

    cout<<"length:"<<len<<endl;

    

    return 0;
}
