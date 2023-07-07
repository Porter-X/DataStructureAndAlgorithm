#include <stdio.h>
#include "sqlist.h"

void test_insert();
void test_purge();
int main()
{
	test_insert();
	test_purge();
	return 0;
}


void test_insert()
{
	sqlink L,R;
	L = sqlist_create();
	if (L == NULL)
		return ;
	//printf("test\n");
	sqlist_insert(L, 10, 0);
	sqlist_insert(L, 20, 0);
	sqlist_insert(L, 30, 0);
	sqlist_insert(L, 40, 0);


	sqlist_show(L);
	printf("test\n");
	sqlist_insert(L, 100, sqlist_length(L));
	printf("test\n");
	sqlist_show(L);
	sqlist_delete(L, 2);
	sqlist_show(L);

}

void test_merge()
{
	sqlink L,R;
	L = sqlist_create();
	R = sqlist_create();
	if (L == NULL || R == NULL)
		return ;
	//printf("test\n");
	sqlist_insert(L, 10, 0);
	sqlist_insert(L, 20, 0);
	sqlist_insert(L, 30, 0);
	sqlist_insert(L, 40, 0);

	sqlist_insert(R, 90, 0);
	sqlist_insert(R, 80, 0);
	sqlist_insert(R, 10, 0);

	sqlist_show(L);
	printf("test\n");
	sqlist_insert(L, 100, sqlist_length(L));
	printf("test\n");
	sqlist_show(L);
	sqlist_delete(L, 2);
	sqlist_show(L);
	
	sqlist_merge(L, R);
	
	sqlist_show(L);

}

void test_purge()
{
	sqlink L,R;
	L = sqlist_create();
	if (L == NULL)
		return ;
	//printf("test\n");
	sqlist_insert(L, 10, 0);
	sqlist_insert(L, 20, 0);
	sqlist_insert(L, 30, 0);
	sqlist_insert(L, 40, 0);
	
	sqlist_insert(L, 10, 0);
	sqlist_insert(L, 20, 0);
	sqlist_show(L);
	printf("purge\n");
	sqlist_purge(L);	
	sqlist_show(L);

}


