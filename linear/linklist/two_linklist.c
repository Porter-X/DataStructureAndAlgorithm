#include <stdio.h>
#include "linklist.h"

int main()
{
	linklist H1;
	linklist H2;
	int i;
	data_t arr1[] = { 1,3,5,6,7};
	data_t arr2[] = { 2,4,5,31,37};
	H1 = list_create();
	if (H1 == NULL)
		return -1;
	H2 = list_create();
	if (H2 == NULL)
		return -1;
	for (i = 0; i < sizeof(arr1)/sizeof(arr1[0]); i++)
		list_tail_insert(H1, arr1[i]);
	for (i = 0; i < sizeof(arr2)/sizeof(arr2[0]); i++)
		list_tail_insert(H2, arr2[i]);
	list_show(H1);
	list_show(H2);

	list_merge(H1,H2);
	list_show(H1);


	return 0;

}
