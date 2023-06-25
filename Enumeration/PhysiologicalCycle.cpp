#include <iostream>
using namespace std; 

/* p 23  e 28 t 33 (i-p)23==0
21252
10 15 20 30
*/ 
//#include "stdio.h"
#define N 23*28*33

int main()
{
    int p=0,e=0,t=0,d=0,caseNo=0;
  while(cin>>p>>e>>t>>d &&p!=-1)
   {
        int i;
        ++caseNo;
        for(i=d+1; (i-p)%23; ++i);//==0 jump out
        for(; (i-e)%28; i+=23);
        for(; (i-t)%33; i+=28*23);
        cout<<"Case "<<caseNo<<" The next triple peak is:"<<i-d<<endl;
        //printf("peak:%d",i-d);
}
    return 0;
}

# if 0
int main(int argc,char *argv[])
{
    int p=0,e=0,t=0,d=100;
    int i;
    //scanf();
    for(i=1; i<=N; i++)//i+=23
    {
        if((i-p)%23==0 && (i-e)%28==0 && (i-t)%33==0)
            if(i>d)
                 printf("i=%d\n",i-d);
    }
    return 0;
}
#endif