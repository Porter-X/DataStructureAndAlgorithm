#include <iostream>
#include <string.h>

using namespace std;

#define SIZE 5

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
int i = 0;
int main(int argc, char const *argv[])
{
    char flower[SIZE];
    char addon[] = "s smell like old shoes";

/*     if (s_gets(flower, SIZE))
    {
        strcat(flower, addon);//cat two strings
        puts(flower);
        puts(addon);
    }
    else
        puts("end of file encountered");
    puts("bye"); */
    int avai;

    s_gets(flower, SIZE);
    //fgets(flower, SIZE, stdin);
    i = strlen(flower);
    cout<<"i = "<<i<<endl;
    avai = SIZE - i - 1;//one space for '\0'
    puts(flower);
    strncat(flower, addon, avai);
    puts(flower);
    return 0;
}
