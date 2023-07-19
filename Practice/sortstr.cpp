#include <iostream>
#include <string.h>

using namespace std;

void sortStr(char **str, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (*str[j] > *str[j + 1])
            {
                char *temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    char **str;
    str = (char**)malloc(n*sizeof(char*));

    for (int i = 0; i < n; i++)
    {

      char buff[100];
      cin>>buff;
      str[i] = (char *)malloc((strlen(buff) + 1) * sizeof(char));
      strcpy(str[i],buff);

    }

    sortStr(str, n);
    
    for (int i = 0; i < n; i++)
        puts(str[i]);
    return 0;
}













/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortStrings(char** strings, int n) {
    char* temp;
    
    // ʹ��ð��������ַ�����������
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(strings[j], strings[j+1]) > 0) {
                // ���������ַ�����λ��
                temp = strings[j];
                strings[j] = strings[j+1];
                strings[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    
    printf("�������ַ����ĸ�����");
    scanf("%d", &n);
    
    // �����ַ�������
    char** strings = (char**)malloc(n * sizeof(char*));
    
    // ��ȡÿ���ַ���
    for (int i = 0; i < n; i++) {
        printf("������� %d ���ַ�����", i+1);
        char buffer[100];
        scanf("%s", buffer);
        
        // �����ڴ沢�����ַ���
        strings[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(strings[i], buffer);
    }
    
    // ���ֵ�˳�������ַ���
    sortStrings(strings, n);
    
    printf("���ֵ�˳���������ַ�����\n");
    
    // ����������ַ���
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }
    
    // �ͷ��ڴ�
    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);
    
    return 0;
} */