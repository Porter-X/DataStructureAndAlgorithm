#include <stdio.h>

//for local variable
void SetBit(int* p, int i)
{
    *p |= 1 << i;

}

void ResetBit(int* p, int i)
{
    *p &= ~(1 << i);
}

int main(int argc, char const *argv[])
{
    int num = 0;
    SetBit(&num, 3);
    printf("Set num: %d\n", num);
    ResetBit(&num, 3);
    printf("Reset num: %d\n", num);
    return 0;
}
