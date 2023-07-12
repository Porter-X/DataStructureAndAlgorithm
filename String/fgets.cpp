#include <iostream>

using namespace std;

#define STLEN 5



int main(int argc, char const *argv[])
{
    char words[STLEN];
    int i;

    puts("please input");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')//input > stlen words[stlen] = '\0'
    {
        i = 0;
        while (words[i] != '\n' && words[i] != '\0')
            i++;
        if (words[i] == '\n')
            words[i] = '\0';
        else
            while (getchar() != '\n');
        puts(words);
    }

    puts("done");
    return 0;
}




/* #include <stdio.h>
#define STLEN 3
int main(void)
{
    char words[STLEN];
    int i;
    
    puts("Enter strings (empty line to quit):");
    while (fgets(words, STLEN, stdin) != NULL
                          && words[0] != '\n')//超过stlen最后一个字符为空
    {
        i = 0;
        while (words[i] != '\n' && words[i] != '\0')
            i++;
        if (words[i] == '\n')
            words[i] = '\0';
        else // must have words[i] == '\0'
            while (getchar() != '\n')
                continue; 
        puts(words);        
    }
    puts("done");
    return 0;
} 
 */