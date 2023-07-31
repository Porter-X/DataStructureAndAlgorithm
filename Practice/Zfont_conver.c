#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char s[] = "PAYPALISHIRING";
    int pos = 0;
    int numRows = 3;
    int length = strlen(s);

    char *pStr = (char *)malloc(sizeof(char)*length + 1);
    pStr[length] = '\0';
    int k = numRows * 2 - 2;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (j%k == i || j%k == k - i)
                pStr[pos++] = s[j];
        }
    }

    puts(pStr);

}
