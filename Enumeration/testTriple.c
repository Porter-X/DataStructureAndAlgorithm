#include "stdio.h"

#define N 100
// a domin [2,N]
// b domin [2,a-1]
// c domin [b,a-1]
// d domin [c,a-1]
int main(int argc,char const *argv[])
{
    int a,b,c,d;
    printf("please input an integer:");
    //scanf("%d",&N);
    for(a=2; a<=N; a++)
    {
        for(d=1;d<=a;d++)
        {
            for(c=1;c<=d;c++)
            {
                for(b=1;b<=c;b++)
                {
                    if(a*a*a==b*b*b+c*c*c+d*d*d)
                    { 
                        printf("Cube=%d,Trible=(%d,%d,%d)\r\n",a,b,c,d);                  
                        break;
                    }
                }
            }
        }
    }
    return 0;
}