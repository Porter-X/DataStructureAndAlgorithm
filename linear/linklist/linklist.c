#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

linklist list_create()
{
	linklist H;
	H = (linklist)malloc(sizeof(linknode));
	if (H == NULL)
		return NULL;
	H->next = NULL;
	H->data = 0;
	return H;

}


int list_tail_insert(linklist H, data_t value)
{
	//1 new node
	linklist N;
	linklist p;
	N = (linklist)malloc(sizeof(linknode));
	if (N == NULL)
		return -1;
	N->next = NULL;
	N->data = value;
	//2 locate
	p = H;
	while (p->next !=NULL)
		p = p->next;//next
	//3 insert
	p->next = N;	
//	p->next->data = value;//N->data = value;

	return 0;
}

int list_show(linklist H)
{
	linklist p;

	if(H ==NULL)
		return -1;
	p = H;
	while(p->next != NULL)
	{
		p = p->next;
		printf("%d ",p->data);
	}
	puts("");
	return 0;
}

linklist list_get(linklist H, int pos)
{
	int i;
	linklist p = H;
	if (pos <=-1)
		return NULL;
	i = -1;
	while (i < pos)
	{
		p = p->next;
		if (p == NULL)
			return NULL;
		i++;
	}

	//printf("%d \n",p->data);
	
	return p;
}

int list_delete(linklist H, int pos)
{
	linklist p;
	linklist q;
	if (H == NULL)
		return -1;
	//locate
	p = list_get(H, pos - 1);
	if (p == NULL)
	 	return -1;
	if(p->next == NULL)
		return -1;
	//updata
	q = p->next;
	p->next = p->next->next;
	//free
	printf("free:%d,addr:%p\n",q->data,q);
	free(q);	
	q = NULL; //no wild pointer
	//printf("free:%d,addr:%p\n",q->data,q);segamentation fault

	return 0;
}

linklist list_free(linklist H)
{
	linklist q;
	q = H;
	if (H == NULL)
		return NULL;
	printf("free:");
	while(H != NULL)//q not q->next
	{
		q = H;
		printf("\n%d ",q->data);
		H = H->next;
		free(q);
	}
	
	puts("");
	H = NULL;
//	free(q);
	return H;
}

