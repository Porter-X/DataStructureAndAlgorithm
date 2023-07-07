#include <stdio.h>
#include "linkqueue.h"

int main()
{
	linkqueue *lq;
	lq = queue_create();
	if (lq == NULL)
		return -1;
	printf("test\n");
	enqueue(lq, 10);
	printf("test\n");
	enqueue(lq, 20);
	enqueue(lq, 30);
	enqueue(lq, 40);
	queue_clear(lq);	
//	while (!queue_empty(lq))
//	{
//		printf("%d ",dequeue(lq));
//	}
//
	//free
	lq = queue_free(lq);
	enqueue(lq,50);
	return 0;

}

