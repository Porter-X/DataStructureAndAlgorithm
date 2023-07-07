#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqstack.h"


sqstack *stack_create(int len)
{
	sqstack *ss;//stack pointer
	if((ss = (sqstack *)malloc(sizeof(sqstack))) == NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}
	if((ss->data = (data_t *)malloc(sizeof(data_t)*len)) == NULL)
	{
		printf("s->data malloc failed\n");
		return NULL;
	}
	memset(ss->data, 0,sizeof(data_t)*len);//init

	ss->maxlen = len;
	ss->top = -1;

	return ss;
}

int stack_push(sqstack *s, data_t value)
{
	if (s == NULL)
		return -1;
	if (s->top == s->maxlen)
		return -1;
//	s++;//stack bottom is to be save
//	*(s->data) = value;//only the first is initialized
	s->top++;
	s->data[s->top] = value;

	return 0;
}

/*
 * @ret 1 empty
 */
int stack_empty(sqstack *s)
{
	if (s == NULL)
		return -1;
	return (s->top == -1 ? 1 : 0);
}

/*
 * @ret 1 full 
 */
int stack_full(sqstack *s)
{
	if (s == NULL)
		return -1;

	return (s->top == s->maxlen -1 ? 1 : 0);
}

data_t stack_pop(sqstack *s)
{
	if (s == NULL)
		return -1;
	s->top--;
	return s->data[s->top+1];
}

int stack_free(sqstack *s)
{
	if (s == NULL)
		return -1;
	if (s->data !=NULL)
		free(s->data);
	free(s);

	return 0;

}
