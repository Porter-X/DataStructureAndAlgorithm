#include <iostream>
#include <string.h>
using namespace std;

#define LISTSIZE 5
#define ANSWER "GRANT"

char *s_gets(char *string, int size)
{
    char *ret;
    int i;
    ret = fgets(string, size, stdin);
    if (ret)
    {
        i = 0;
        while (string[i] != '\n' && string[i] != '\0')
            i++;
        if (string[i] == '\n')
            string[i] = '\0';
        else
            while (getchar() != '\n');//clear buffer
    }

    return ret;
}

int main(int argc, char const *argv[])
{

    const char *list[LISTSIZE] = {
        "abcd","abdc","abef","cdcd","xx"
    };
    for ( int i = 0; i < LISTSIZE; i++)
        if (strncmp(list[i], "ab",2) == 0)//n char compare in the string return value 0 represents ture
        {
            cout<<"i :"<<i<<endl<<list[i]<<endl;     
        }
    return 0;
}
