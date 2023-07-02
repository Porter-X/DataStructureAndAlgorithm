#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sqlist.h"

sqlink sqlist_create()
{
	sqlink L;
	L = (sqlink)malloc(sizeof(sqlist));
	if(NULL == L)
	{
		printf("create failed\n");
		return L;
	}
	memset(L, 0, sizeof(sqlist));
	L->last = -1;
	return L;
}

/* sqlist_clear: clear the sqlist
 * para L: list 
 * @ret 0-success -1-failed
 */
int sqlist_clear(sqlink L)
{
	if (NULL == L)
		return -1;
	
	memset(L, 0, sizeof(sqlist));
	L->last = -1;

	return 0;
}


int sqlist_free(sqlink L)
{
	if (L ==NULL)
		return -1;
	free(L);
	L = NULL;

	return 0;
}
/* sqlist_empty: is L empty 
 * para L: list 
 * @ret 1--empty 0--not empty
 */
int sqlist_empty(sqlink L)
{
	if (L->last == -1)
		return 1;
	else
		return 0;
}
int sqlist_length(sqlink L)
{
	if (L == NULL)
		return -1;
	return L->last + 1;
}
int sqlist_locate(sqlink L, data_t value)
{
	for (int i = 0; i <= L->last; i++)
		if (L->data[i] == value)
			return i;
	
	return -1;
}
int sqlist_insert(sqlink L, data_t value, data_t pos)
{
	//full
	if (L->last == N -1)
	{
		printf("list is full\n");
		return -1;
	}
	//check para 0<=pos<=last+1
	if (pos < 0 || pos > L->last + 1)
	{
		printf("pos is invalid\n");
		return -1;
	}
	//move
	for (int i = L->last; i >= pos; i--)
	{
		L->data[i + 1] = L->data[i];
	}
	//updata value last
	L->data[pos] = value;
	L->last++;
	return 0;
}

int sqlist_show(sqlink L)
{
	int i;
	if (L == NULL)
		return -1;
	if (L->last == -1)
		printf("list is empty\n");

	for (i = 0; i <= L->last; i++)
		printf(" %d ",L->data[i]);
	puts("");//\r\n

	return 0;
}

int sqlist_delete(sqlink L, int pos)
{
	if (L == NULL)
		return -1;
	if (pos < 0 || pos > L->last)
	{
		printf("pos invalid\n");
		return -1;
	}
	
	for (int i = pos; i < L->last; i++)//delete 1 element
	{
		L->data[i] = L->data[i + 1];
	}	
	L->last--;
	

	return 0;
}

int sqlist_merge(sqlink L, sqlink R)
{
	int i = 0;
	int ret;
	if (L == NULL || R == NULL)
		return -1;
	while (i <= R->last)
	{
		ret = sqlist_locate(L, R->data[i]);
		if (ret == -1)
			sqlist_insert(L, R->data[i], L->last + 1);
		i++;//next elemnt
		
	}	

	return 0;
}

int sqlist_purge(sqlink L)
{
	int i = 1;
	while (i <= L->last)
	{
		int j = i - 1;
		while (j >= 0)
		{
			if (L->data[i] == L->data[j])
			{
				sqlist_delete(L, i);
				break;
			}
			j--;
		}
		if (j < 0)
			i++;//do not increase after deleting	
	}
		
	return 0;
}
