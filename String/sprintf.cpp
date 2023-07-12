#include <iostream>

using namespace std;

#define SIZE 4

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
    char string[2*SIZE + 5];
    char first[SIZE];
    char last[SIZE];
    int prize;
    puts("enter youre first name");
    s_gets(first, SIZE);
    puts("enter youre last name");
    s_gets(last, SIZE);
    puts("enter your money");
    //fgets(prize, SIZE, stdin);    
    cin>>prize;

    sprintf(string,"%s£¬%s: %d\n",first, last, prize);

    puts(string);

    return 0;
}
