#include <stdio.h>
#include "linkqueue.h"
#include "sqstack.h"

int main()
{
	linkqueue *lq;
	sqstack *s_min, *s_five, *s_hour;

	int i;
	int min = 0;
	if((lq = queue_create()) == NULL)
		return -1;

	for (i = 1; i <= 27; i++)
		enqueue(lq, i);
	if ((s_min = stack_create(4)) == NULL)
		return -1;
	if ((s_five = stack_create(11)) == NULL)
		return -1;
	if ((s_hour = stack_create(11)) == NULL)
		return -1;

	while(1)
	{
		min++;
		if (!stack_full(s_min))
		{
			stack_push(s_min, dequeue(lq));
		}
		else
		{
			while (!stack_empty(s_min))
				enqueue(lq, stack_pop(s_min));
			if(!stack_full(s_five))
			{
				stack_push(s_five, dequeue(lq));
			}
			else
			{
				while (!stack_empty(s_five))
					enqueue(lq, stack_pop(s_five));
				if(!stack_full(s_hour))
				{
					stack_push(s_hour, dequeue(lq));
				}
				else
				{
					while (!stack_empty(s_hour))
						enqueue(lq,stack_pop(s_hour));
					enqueue (lq, dequeue(lq));		
					if (check(lq))//queue has 27 elements
					{
						printf("min:%d \n",min);
						break;
					}
				}

			}

		}
	}
	while (!queue_empty(lq))
	{
		printf("%d ",dequeue(lq));
	}

	return 0;
}

