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
    //去重
    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = i + 1; j < cnt; j ++)
        {
            if (arr[i] == arr[j])
            {
                //移动元素
                move(arr, j, cnt);
                cnt--;  //避免arr数组为零的重复比较
            }
        }
    }

    //打印输出
    for (int i = 0; i < cnt ; i++)
        cout<<arr[i];

    return 0;
} */
//更好的解法
#include <stdio.h>

int removeDuplicates(int num) {
    int result = 0;
    int digits[10] = { 0 }; // 数字出现的标记数组，初始值为0

    while (num > 0) {
        int digit = num % 10; // 取出最右边的数字

        if (digits[digit] == 0) {
            result = result * 10 + digit; // 将不重复的数字添加到结果中
            digits[digit] = 1; // 标记该数字已经出现过
        }

        num = num / 10; // 去掉最右边的数字
    }

    return result;
}

int main() {
    int num;
    printf("请输入一个整数：");
    scanf("%d", &num);

    int newNum = removeDuplicates(num);
    printf("从右向左的阅读顺序，不含重复数字的新整数为：%d\n", newNum);

    return 0;
}