/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 * 
 * @param s string�ַ��� 
 * @param n int���� 
 * @return string�ַ���
 */
 void reverse(char *s, int head, int tail)
 {
    //˫ָ��
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
    //��Сдת��
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
    //�����ַ���
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