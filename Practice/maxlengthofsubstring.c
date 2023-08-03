int lengthOfLongestSubstring(char * s){
    int length = strlen(s);
    printf("length %d\n",length);
    if (length == 1)
        return 1;
    int cnt= 0;
    int max = 0;
    int temp = 0;
    int flag = 0;
    int norep = 0;
    for (int i = 0; i < length; i++)// 遍历每一个字符
    {
        for (int j = i + 1; j < length; j++)
        {
            cnt++;
            for (int k = i; k < j; k++)//与前面的所有字符对比
            {
                if (s[k] == s[j])//相同记录下来
                {
                    temp = cnt;
                    cnt = 0;
                    flag = 1;
                    printf("i:%d temp : %d\n",i,temp);
                    break;
                }     
            }
            if (flag == 1)
                {
                    flag = 0;
                    break;
                }
        }
        if (temp > max )//最大值标记
           {
                max = temp;
                norep = 1;
                printf("max: %d\n",max);
           }

    }
    if (norep == 0)
    {
        return length;
    }

    return max;
}