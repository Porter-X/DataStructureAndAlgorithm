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

//ʾ������ ���������ʹ��
#include <stdio.h>

int countDistinctChars(const char* str) {
    int distinctChars = 0;
    int charMap[256] = { 0 }; // ���ڼ�¼�ַ��������������

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        char ch = str[i];

        // ������ַ���δ���ֹ��������Ӳ�ͬ�ַ��ļ�������������charMap�б��Ϊ�ѳ���
        if (charMap[ch] == 0) {
            distinctChars++;
            charMap[ch] = 1;
        }
    }

    return distinctChars;
}

int main() {
    char str[100];
    printf("������һ���ַ�����");
    fgets(str, sizeof(str), stdin);

    int count = countDistinctChars(str);
    printf("��ͬ�ַ��ĸ���Ϊ��%d\n", count);

    return 0;
}