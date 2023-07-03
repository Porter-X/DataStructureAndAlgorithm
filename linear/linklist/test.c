#include <stdio.h>
#include "linklist.h"


int main()
{
	linklist H;
	int value;
	linklist p;
	H = list_create();
	if (H == NULL)
		return -1;
	printf("%p \n",H);
	printf("input:");

	while(1)
	{
		scanf("%d",&value);
		if(value == -1)
			break;
		list_tail_insert(H,value);
		printf("input:");
	}
	printf("%p \n",H);
	list_show(H);

	p = list_get(H, 2);
	if (p !=NULL)
		printf("value:%d\n",p->data);
	list_delete(H, 2);
	list_show(H);
	H = list_free(H);
	list_free(H);
///	list_show(H);
	return 0;
}
