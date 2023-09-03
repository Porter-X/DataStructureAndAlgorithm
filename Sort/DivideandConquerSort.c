#include <stdio.h>

//�鲢�����㷨�����������Ĳ�����һ���Ƿ֣�
//Ҳ���ǰ�ԭ���黮�ֳ�����������Ĺ��̡�
//��һ�����Σ�����������������ϲ���һ��������������顣
//���ĵĹ鲢�������ǲ��õݹ�ȥʵ�֣�Ҳ�ɲ��õ����ķ�ʽȥʵ�֣���
//�ֽ׶ο������Ϊ���ǵݹ��������еĹ��̣��ݹ����Ϊlog2n��
/* �㷨����
�ٶȽ����ڿ�������ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(N)��
�鲢������Ҫһ����ԭ������ͬ���ȵ����������������� */
int arr[5] = {4,5,3,2,1};
int temp[5];
void Merge(int arr[], int s,int m, int e, int temp[])
{
    int pb = 0;
    int pb1 = s;
    int pb2 = m + 1;
    while (pb1 <= m && pb2 <= e)
    {
        if (arr[pb1] < arr[pb2])
            temp[pb++] = arr[pb1++];
        else
            temp[pb++] = arr[pb2++];
    }
    while (pb1 <= m)
    {
        temp[pb++] = arr[pb1++];
    }
    while (pb2 <= e)
    {
        temp[pb++] = arr[pb2++];
    }
    for (int i = 0; i < e-s+1; i++)
        arr[s + i] = temp[i];

}

void MergeSort(int arr[], int s, int e, int temp[])
{
    if (s < e)
    {
        int mid = s + (e - s)/2; // ���(e + s)/2
        MergeSort(arr, s, mid, temp);//��
        MergeSort(arr, mid + 1, e, temp);
        Merge(arr, s, mid, e, temp);//��
    }
}
int main(int argc, char const *argv[])
{
    /* code */  
    int size = sizeof (arr)/sizeof(arr[0]);
    MergeSort(arr, 0, size - 1, temp);

    for (int i = 0; i < size; i++)
        printf("%d ",arr[i]);
    return 0;
}
