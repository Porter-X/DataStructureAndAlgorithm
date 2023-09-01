 #include <stdio.h>
#include <stdbool.h>
 bool isMatch(char * p, int *stack, int *top)
    {
        switch (*p)
        {
            case ')':
                return stack[(*top)--] == '(';//true or false
            case ']':
                return stack[(*top)--] == '[';
            case '}':
                return stack[(*top)--] == '{';
            default :
                return false;                                        
        }
    }

bool isValid(char * s)
{
    int stack[10000];
    int top = -1;
    if (strlen(s) % 2 == 1 || (*s == ')' || *s == ']' || *s == '}'))//????? ????????????
        return false;
    
    while (*s != '\0')
    {
        if (*s == '(' || *s == '[' || *s == '{')//?????
        {
            stack[++top] = *s;
        }
        else if (*s == ')' || *s == ']' || *s == '}')//???????
        {
           //?????
            if (top == -1 || !isMatch(s, stack, &top))
                return false;
        }
        s++;
    }
    if (top == -1)//??????
        return true;
     else
        return false;
}