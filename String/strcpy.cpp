#include <iostream>
#include <string.h>

using namespace std;

#define SIZE 6


int main(int argc, char const *argv[])
{
    char des[SIZE] = "abcde";//the number of char equals size - 1 
    char src[SIZE] = "qwert";
    strncpy(des, src, 3);

    cout<<"des :"<<des<<" "<<"src :"<<src<<endl;

    return 0;
}
