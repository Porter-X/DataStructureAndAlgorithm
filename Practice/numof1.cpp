#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int cnt = 0;
    int num;
    cin >> num;

    while (num)
    {
        if (num & 1)
            cnt++;
        num = num >> 1;
    }

    cout << cnt <<endl;
    return 0;
}
