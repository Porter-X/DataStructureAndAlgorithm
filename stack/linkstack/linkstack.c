#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"

linkstack stack_create(void)
{
	linkstack s;
	s = (linkstack)malloc(sizeof(linknode));
	if (s == NULL)
		return NULL;
	s->data = 0;
	s->next = NULL;

	return s;
}
int stack_push(linkstack s, data_t value)
{
	linkstack p;
	if ( s == NULL)
		return -1;
	p = (linkstack)malloc(sizeof(linknode));
	if (p == NULL)
		return -1;
      	p->next = s->next;	
	s->next = p;
	p->data = value;

	return 0;

}
data_t stack_pop(linkstack s)
{
	linkstack p;
	data_t temp;
	if ( s == NULL)
		return -1;
	p = s->next;
	s->next = p->next;
	temp = p->data;
	free(p);	
	
	return temp;

}
int stack_empty(linkstack s)
{
	return s->next == NULL ? 1 : 0;
}
//int stack_top(linkstack s);
//int stack_free(linkstack s);

