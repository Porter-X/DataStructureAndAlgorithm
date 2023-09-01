#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void  getParenthesis(char **result, char *current, int left, int right, int max, int *returnSize)
{
    if (strlen(current) == 2 * max)//递归退出条件
    {
        result[*returnSize] = (char *)malloc(sizeof(char) *(2 * max + 1));
        //printf("test %s\n",current);
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return ;
    }

    if (left < max)
    {
        current[strlen(current)] = '(';
        getParenthesis(result, current, left + 1, right, max, returnSize);
        current[strlen(current) - 1] = '\0';//往后退一个
    }
    
    if (right < left)
    {
        current[strlen(current)] = ')';
        getParenthesis(result, current, left, right + 1, max, returnSize);
        current[strlen(current) - 1] = '\0';//往后退一个
    }
}
char ** generateParenthesis(int n, int* returnSize){
    char **result = (char **)malloc(sizeof(char *)*10000);
    char *current = (char *)malloc(sizeof(char) * (2 * n + 1));//最多2n个字符还有一个'\0'
    memset(current, '\0', 2 * n + 1);
    * returnSize = 0; //清零
    getParenthesis(result, current, 0, 0, n, returnSize);
    free(current);//current free
    return result;
}

int main(int argc, char const *argv[])
{
    int n = 8;
    int returnSize = 0;
    //printf("%c",'\253');
    char ** result = generateParenthesis(n, &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        printf("%s\n",result[i]);
        free(result[i]);//用一个free一个
    }
    free(result);
    return 0;
}
