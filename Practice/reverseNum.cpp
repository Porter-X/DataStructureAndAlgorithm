#include <iostream>
using namespace std;

/* void move (int *arr,int s, int n)//s -> start n - >size
{
    for (int i = s; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
}
int main(int argc, char const *argv[])
{
    int num,i = 0;
    int arr[15] = {0};
    cin >> num;
    int cnt = 0;

    while (num % 10)
    {
        cnt ++;
        arr[i++] = num % 10;
        num /= 10;
    }
    //ȥ��
    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = i + 1; j < cnt; j ++)
        {
            if (arr[i] == arr[j])
            {
                //�ƶ�Ԫ��
                move(arr, j, cnt);
                cnt--;  //����arr����Ϊ����ظ��Ƚ�
            }
        }
    }

    //��ӡ���
    for (int i = 0; i < cnt ; i++)
        cout<<arr[i];

    return 0;
} */
//���õĽⷨ
#include <stdio.h>

int removeDuplicates(int num) {
    int result = 0;
    int digits[10] = { 0 }; // ���ֳ��ֵı�����飬��ʼֵΪ0

    while (num > 0) {
        int digit = num % 10; // ȡ�����ұߵ�����

        if (digits[digit] == 0) {
            result = result * 10 + digit; // �����ظ���������ӵ������
            digits[digit] = 1; // ��Ǹ������Ѿ����ֹ�
        }

        num = num / 10; // ȥ�����ұߵ�����
    }

    return result;
}

int main() {
    int num;
    printf("������һ��������");
    scanf("%d", &num);

    int newNum = removeDuplicates(num);
    printf("����������Ķ�˳�򣬲����ظ����ֵ�������Ϊ��%d\n", newNum);

    return 0;
}