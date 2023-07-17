#include <iostream>
#include <string.h>

using namespace std;

/* int main(int argc, char const *argv[])
{
    string str;
    int num;
    cin >> num;
    while (num != 0)
    {
        char c = num % 10 + '0';
        num /= 10;
        str += c;
    }

    cout << str <<endl;
    return 0;
} */
void reverseString(char *str)
{
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end)
    {
        int temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }

}
int main(int argc, char const *argv[])
{
    int num;
    char str[20];
    cin >> num;

    sprintf(str,"%d",num);

    reverseString(str);

    puts(str);
    
    return 0;
}
