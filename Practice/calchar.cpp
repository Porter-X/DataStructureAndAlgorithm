#include <iostream>
#include <string.h>

using namespace std;

/* int main(int argc, char const *argv[])
{
    char arr[10];
    gets(arr);

    int len = strlen(arr);
    int cnt = len;
    for (int i = 0; i < len ; i++)
    {
        if (strchr(&arr[i] + 1, arr[i]))
            cnt--;
    }

    cout << cnt<<endl;
    return 0;
} */

//示例代码 辅助数组的使用
#include <stdio.h>

int countDistinctChars(const char* str) {
    int distinctChars = 0;
    int charMap[256] = { 0 }; // 用于记录字符出现情况的数组

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        char ch = str[i];

        // 如果该字符尚未出现过，则增加不同字符的计数，并将其在charMap中标记为已出现
        if (charMap[ch] == 0) {
            distinctChars++;
            charMap[ch] = 1;
        }
    }

    return distinctChars;
}

int main() {
    char str[100];
    printf("请输入一个字符串：");
    fgets(str, sizeof(str), stdin);

    int count = countDistinctChars(str);
    printf("不同字符的个数为：%d\n", count);

    return 0;
}