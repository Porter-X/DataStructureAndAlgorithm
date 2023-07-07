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

int list_reverse(linklist H)
{
	linklist p;
	linklist q;
	if (H == NULL)
		return -1;
	p = H->next->next;
	H->next->next = NULL;
	while (p != NULL)
	{
		//q is to save p->next		
//		q = p->next;
//		H->next = p;
//		p = q;
		//q is to save p
		q = p;
		p = p->next;
		q->next = H->next;
		H->next =q;
	}	
	
	return 0;
}


linklist list_adjmax(linklist H, data_t *value)
{
	linklist p;
	linklist q;
	linklist temp;
	int max = 0;
	if (H == NULL)
		return NULL;
	p = H->next;
	q = H->next->next;
	if (H->next ==NULL || H->next->next == NULL)
		return NULL;
	while (q != NULL)//what if two nodes in the list,it's q,not q->next
	{
	if ( p->data + q->data > max)
	{
		max = p->data + q->data;
		temp = p;
		printf("max: %d\n",max);
	}
	p = p->next;
	q = q->next;
	}
	*value = max;//pointer 
	return temp;
}

int list_merge(linklist H1, linklist H2)
{
	linklist p;
	linklist q;
	linklist r;

	if (H1 == NULL || H2 == NULL)
		return -1;

	p = H1->next;
	q = H2->next;
	r = H1;
	while (p != NULL && q != NULL)
	{
		if (p->data <= q->data)
		{
			r->next = p;
			p = p->next;
			r = r->next;
			r->next = NULL;

		}
		else
		{
			r->next = q;
			q = q->next;
			r = r->next;
			r->next = NULL;
		}
	}
	printf("list_merge\n");
	
	if (p == NULL)
		r->next = q;
	else
		r->next = p;
	return 0;


}
