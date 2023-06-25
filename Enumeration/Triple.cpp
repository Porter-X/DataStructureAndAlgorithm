#include <iostream>
using namespace std;
#define N 100

int main(int argc, char const *argv[])
{
    int a,b,c,d;
    for(a=1;a<N;a++)
        for(b=2;b<a-1;b++)
           for(c=b;c<a-1;c++)
              for(d=c;d<a-1;d++)
                if(b*b*b+c*c*c+d*d*d==a*a*a)
                    printf("Cube=%d,b=%d,c=%d,d=%d\n",a,b,c,d);
    return 0;
}
