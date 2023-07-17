#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    float num;
    cin >> num;
    if (num - int(num) >= 0.5)
    {
        cout<<(int)(num + 1)<<endl;
    }
    else
    {
        cout<<(int)num<<endl;
    }
    return 0;
}
