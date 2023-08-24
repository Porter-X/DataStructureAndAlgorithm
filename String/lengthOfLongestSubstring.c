int lengthOfLongestSubstring(char * s)
{
    int left = 0;//双指针
    int right = 0;
    int length = strlen(s);
    int havesamechar = 0;
    int max = 0;
    int i = 0, j = 0;

    for (i = 0; i < length; i++)//遍历每一个字符
    {
        if (left <= right)
        {
            for (j = left; j < right; j++)
            {
                if (s[j] == s[right])
                {
                    havesamechar = 1;
                    break;
                }
            }
            if (havesamechar)
            {
                left = j + 1;//遇到重复的指向下一个
                havesamechar = 0;//置零
            }
        }
        max = max > (right - left + 1)? max: (right - left + 1);
        right++;
    }

    return max;
}