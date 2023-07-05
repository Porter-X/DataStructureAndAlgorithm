typedef int data_t;

typedef struct node{
	data_t data;
	struct node *next;
}linknode,*linkstack;

linkstack stack_create(void);
int stack_push(linkstack s, data_t value);
int stack_pop(linkstack s);
int stack_empty(linkstack s);
int stack_top(linkstack s);
int stack_free(linkstack s);

