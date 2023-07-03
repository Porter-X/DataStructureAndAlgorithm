
typedef int data_t;

typedef struct node{
	data_t data;
	struct node *next;
}linknode,*linklist;

linklist list_create(void);
int list_tail_insert(linklist H, data_t value);
linklist list_get(linklist H, int pos);
int list_show(linklist H);
int list_delete(linklist H, int pos);
linklist list_free(linklist H);
