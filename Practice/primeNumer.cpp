#include <iostream>

using namespace std;

int isPrime(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i * i < n; i++)// i * i 减少判断
    {
        if (n % i == 0)
        {
            return 0;
        }    
    }
    
    return 1;
}

int main(int argc, char const *argv[])
{
    int num;
/*     while (cin>>num)//寻找质因子
    {
        //循环从小到大的质数因子 2,3,5,7,11
        for (int i = 2; i <= num; i++)
        {
            while (num % i ==0)
            {
                cout <<i<<' ';
                num/=i;
            }
        }
    } */
    cin>>num;

    if (isPrime(num))
        cout << "prime number";
    else
        cout <<"not prime number";

    return 0;
}
