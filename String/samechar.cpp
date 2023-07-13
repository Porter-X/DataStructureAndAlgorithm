#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    char str[100];
    char ch;
    int i = 0, cnt = 0;
    gets(str);
    cin>>ch;

    for (i = 0; str[i] != '\0'; i++)// str[i] != '\0'
    {
        if (str[i] == ch || str[i] - 32 == ch || str[i] + 32 == ch)//'a' == 97 'A' == 65
            cnt++;
    }

    cout<<"count :"<<cnt<<endl;

    return 0;
}
