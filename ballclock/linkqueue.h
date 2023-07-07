

typedef int data_t;

typedef struct node{
	data_t data;
	struct node *next;
}linknode, *linklist;

typedef struct {
	linklist front,rear;
}linkqueue;

linkqueue * queue_create();
int enqueue(linkqueue * lq, data_t value);
data_t dequeue(linkqueue *lq);
int queue_empty(linkqueue *lq);
int queue_clear(linkqueue *lq);
linkqueue * queue_free(linkqueue *lq);

int check(linkqueue *lq);
