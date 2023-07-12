#include <iostream>
#include <string.h>

#define SIZE 6
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
    char arr[SIZE];
    puts(" input a string");
    s_gets(arr, SIZE);
    while (strcmp(arr, ANSWER))//compare string
    {
        puts("NOT RIGHT TRY AGAIN");
        s_gets(arr,SIZE);
    }

    puts("RIGHT");

    return 0;
}
