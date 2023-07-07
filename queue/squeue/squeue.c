#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "squeue.h"

pSqueue squeue_create()
{
	pSqueue sq;
	if((sq = ((pSqueue)malloc(sizeof(squeue)))) == NULL)
		return NULL;
	sq->front = sq->rear = 0;//init
	sq->data[sq->rear] = 0;

	return sq;

}

int enqueue(pSqueue sq,data_t value)
{
	if (sq == NULL)
		return -1;
	if (!queue_full(sq))
	{
		sq->data[sq->rear] = value;//point next element
		sq->rear = (sq->rear + 1) % N;
	}
	return 0;
}

data_t dequeue(pSqueue sq)
{
	data_t temp;
	if (sq == NULL)
		return -1;
	if (!queue_empty(sq))
	{
		temp = sq->data[sq->front];
		sq->front = (sq->front + 1) % N;
	}

	return temp;

}

int queue_empty(pSqueue sq)
{
	return (sq->front == sq->rear  ? 1 : 0);
}

int queue_full(pSqueue sq)
{
	if (sq->front == sq->rear + 1)
		return 1;
	return 0;
	
}

int queue_clear(pSqueue sq);

pSqueue queue_free(pSqueue sq)
{
	if (sq == NULL)
		return NULL;

	free(sq);

	sq = NULL;

	return NULL;
}

		
