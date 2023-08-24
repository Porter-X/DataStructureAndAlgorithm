void BubleSort(int *array, int size)
{

        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (array[j] > array[j + 1])// size - i - 1 避免j + 1越界
                {
                    //swap
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }

}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double ret = 0;
    int *array = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
    
    for (int i = 0; i < nums1Size; i++)
    {
        array[i] = nums1[i];
    }
    for (int i = 0; i < nums2Size; i++)
    {
        array[nums1Size + i] = nums2[i];
    }
    //排序
    BubleSort(array, nums1Size + nums2Size);

    for (int i = 0; i < nums1Size + nums2Size; i++)
    {
       printf("%d ",array[i]);
    }

    if ((nums2Size + nums1Size)%2)
    {
        //奇a数
        ret = array[(nums2Size + nums1Size) / 2];
    }
    else
    {
        //偶数
        ret = (array[(nums2Size + nums1Size) / 2] + array[(nums2Size + nums1Size) / 2 - 1])/2.0;
    }
    return ret;
}