#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int rows = 3;
    int cols = 4;
    int **matrix = (int **)malloc(sizeof(int *) * rows);//指针指向 int *matrix[rows];
    if (matrix == NULL)
    {
        puts("malloc failed");
        return -1;
    }
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * cols);
    }

    //初始化数组
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = i * cols + j;
        }
    }    


    //打印数组
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ",matrix[i][j]);
        }
        puts("");
    }    

    return 0;
}
