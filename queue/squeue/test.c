#include <stdio.h>
#include "squeue.h"

int main()
{
	pSqueue sq;
	if((sq = squeue_create()) == NULL)
		return -1;

	enqueue(sq, 10);
	enqueue(sq, 20);
	enqueue(sq, 30);

	while (!queue_empty(sq))
	{
		printf("%d ",sq->data[sq->front++]);
	}
	//free
	queue_free(sq);

	return 0;
}
