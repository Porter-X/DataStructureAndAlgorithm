#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkqueue.h"

linkqueue * queue_create()
{
	linkqueue *lq;
	linklist ls;
	lq = (linkqueue*)malloc(sizeof(linkqueue));//head rear pointer
	if (lq == NULL)
	{
		printf("malloc node failed\n");
		return NULL;
	}
	ls = (linklist)malloc(sizeof(linknode));//node pointer
	if (ls == NULL)
		return NULL;

	lq->front = ls;
	lq->rear = ls;
	//lq->front = (linklist)malloc(sizeof(linknode));
//	lq->rear = lq->front;
//	if (lq->front == NULL)
//	{
//		printf("malloc node failed\n");
//		return NULL;
//	}
//
	lq->front->data = 0;
	lq->front->next = NULL;

	return lq;
}
int enqueue(linkqueue * lq, data_t value)
{
	
	linklist ls;
	if (lq == NULL)
	{
		printf("lq is NULL\n");
		return -1;
	}
	if ((ls = (linklist)malloc(sizeof(linknode))) == NULL)	
	{
		printf("malloc a new node failed\n");
		return -1;
	}
	//tail insert front exit
	//lq->rear++//link
	ls->data = value;
	ls->next = NULL;	
	
	lq->rear->next = ls;
        lq->rear = ls;	
	
	return 0;
}
data_t dequeue(linkqueue *lq)
{
	linklist p;
	if (lq == NULL)//attention= ==
	{
		printf("lq is NULL\n");
		return -1;
	}
	p = lq->front;
	lq->front = lq->front->next;

	free(p);
	p = NULL;

	return (lq->front->data);
}
int queue_empty(linkqueue *lq)
{

	if (lq == NULL)
	{
		printf("lq is NULL\n");
		return -1;
	}
	return (lq->front == lq->rear ? 1 : 0);
}
int queue_clear(linkqueue *lq)//clear node,queue and head pointer head node are kept
{
	linklist p;
	if (lq == NULL)
		return -1;
	while (lq->front->next != NULL)
	{
		p = lq->front;
		lq->front = p->next;
		printf("clear %d \n",p->data);
		free(p);
		p = NULL;
	}

	return 0;
}

linkqueue * queue_free(linkqueue *lq)//free node,head pointer queue
{
	linklist p;
	while (lq->front)
	{
		p = lq->front;
		lq->front = lq->front->next;
		printf("free:%d \n",p->data);
		free(p);//free node
	}
	free(lq);//free front and rear pointer
	lq =NULL;

	return NULL;//queue pointer
}

int check(linkqueue *lq)
{
	linklist p;

	p = lq->front->next;

	while (p && p->next)
	{
		if (p->data < p->next->data)
		{
			p = p->next;
		}
		else
			return 0;
	}

	return 1;
}
