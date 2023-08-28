#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(char * s){
    char *p = s;

    while (*p != '\0')
    {
        if ( *p == '(')
        {
            p++;
            if (*p == ']' || *p == '}')//if  (*p != ')')
            {
                return false;
            }
            else if (*p == ')')
            {
                char *temp = p - 1;
                if (*temp != '(')
                    return false;
            }
        }
        else if ( *p == '{')
        {
             p++;
            if  (*p == ']' || *p == ')')
            {
                return false;
            }
        }
        else if ( *p == '[')
        {
             p++;
            if  (*p == ')' || *p == '}')
            {
                return false;
            }
        }

        else if (*p == '}')
        {
            char *temp = p - 1;
            if (*temp != '{')
                return false;
        }
        else if (*p == ']')
        {
            char *temp = p - 1;
            if (*temp != '[')
                return false;
        }        
    }

    return true;
}


int notMatch(char par, char* stack, int stackTop)
{
    switch(par)
    {
        case ']':
            return stack[top]
    }
}

bool isValid(char * s){
    int length = strlen(s);
    char *stack = (char *)malloc(sizeof(int) * length);
    int top = 0;
    if (length % 2 == 1)
        return false;
    for (int i = 0; i < length; i++)
    {
        char temp = s[i];
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')//ÓÒÀ¨ºÅ
        {
            stack[top++] = s[i];
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')//×óÀ¨ºÅ
        {
            if (top == 0 || notMatch(temp, stack, top))
                return 0;
        }
    }

    return true;
}