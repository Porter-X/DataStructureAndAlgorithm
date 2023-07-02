

typedef int data_t;
#define N 100 

typedef struct{
	data_t data[N];
	int last;
}sqlist,*sqlink;

//operations
sqlink sqlist_create();
int sqlist_clear(sqlink L);
int sqlist_empty(sqlink L);
int sqlist_length(sqlink L);
int sqlist_locate(sqlink L, data_t value);
int sqlist_insert(sqlink L, data_t value, data_t pos);
int sqlist_show(sqlink L);
int sqlist_free(sqlink L);
int sqlist_delete(sqlink L, int pos);
int sqlist_merge(sqlink L, sqlink R);
int sqlist_purge(sqlink L);
