#include <stdio.h>

/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 * 
 * @param nums int����һά���� 
 * @param numsLen int nums���鳤��
 * @return int����
 */
int findPeakElement(int* nums, int numsLen ) {
    // write code here
    if (nums[0] > nums[1])
        return 0;
    else if (nums[numsLen - 1] > nums[numsLen - 2])
        return numsLen - 1;
    
/*     for (int i = 1; i < numsLen - 1; i++)//����
    {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            return i;
    } */
    int left = 0;//���ֲ���
    int right = numsLen - 1;
    while (left < right)
    {
        int mid = left + (right - left)/2;
        if (nums[mid] < nums[mid + 1])
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int binarySearch(int arr[], int size, int target)
{
    int l = 0;
    int r = size - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (target > arr[mid])
        {
            l = mid + 1;
        }
        else if (target == arr[mid])
        {
            return mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[5] = {1,2,3,4,5};
    int ret = binarySearch(arr, sizeof(arr)/sizeof(arr[0]), 5);

    printf("ret :%d\n", ret);
    return 0;
}
