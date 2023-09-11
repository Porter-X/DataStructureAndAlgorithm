/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param s string字符串 
 * @param n int整型 
 * @return string字符串
 */
 void reverse(char *s, int head, int tail)
 {
    //双指针
    while (head < tail)
    {
        char tempHead = s[head];
        char tempTail = s[tail];
        s[head] = tempTail;
        s[tail] = tempHead;
        head++;
        tail--;
    }
 }

char* trans(char* s, int n ) {
    
    // write code here
    //char temp[100000];
    printf("A-a :%d\n",'A' - 'a');
    //大小写转换
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 32;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
    }
    //逆序字符串
    reverse(s, 0, n - 1);
    int i = 0,start = 0;
    while (i <= n)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {
            reverse(s,start,i - 1);
            start = i + 1;            
        }   
        i++;
    }
/*     for (int i = 0; i < n; i++)
        temp[i] = s[n - i - 1] ; */

    return s;
}