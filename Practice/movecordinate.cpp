#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    char input[100];
    //char temp[10];
    int i = 0, cnt = 0;
    int x = 0, y = 0;
    gets(input);

    while (input[i] != '\0')
    {
        int j = i;
        cnt = 0;//¼ÆÊıÇåÁã
        while (input[i] != ';')
        {
            i++;
            cnt++;
            if ( input[i] == '\0')
                break;
        }
        if (cnt == 3)
        {
            if (input[j + 1] >= '0' && input[j + 1] <='9' && input[j + 2] >= '0' && input[j + 2] <='9')
            {
                switch(input[j])
               {
                case 'A': x -=(input[j + 1] - '0')*10 + input[j + 2] - '0'; break;
                case 'D': x +=(input[j + 1] - '0')*10 + input[j + 2] - '0'; break;
                case 'W': y +=(input[j + 1] - '0')*10 + input[j + 2] - '0'; break;
                case 'S': y -=(input[j + 1] - '0')*10 + input[j + 2] - '0'; break;
                default : break;
               } 
            }
        }
        else if (cnt == 2)
        {
            if (input[j + 1] >= '0' && input[j + 1] <='9' && input[j + 2] >= '0' && input[j + 2] <='9')
            {
                switch(input[j])
               {
                case 'A': x -=(input[j + 1] - '0'); break;
                case 'D': x +=(input[j + 1] - '0'); break;
                case 'W': y +=(input[j + 1] - '0'); break;
                case 'S': y -=(input[j + 1] - '0'); break;
                default : break;
               } 
            }            
        }
        else
        {
            //daiding
        }
        i++;

    }

    cout <<"x:"<<x<<endl<<"y:"<<y<<endl;
    return 0;
}
