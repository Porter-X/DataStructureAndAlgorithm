typedef int data_t;
#define N 6

typedef struct{
	data_t data[N];
	int front;
	int rear;
}squeue,* pSqueue;

pSqueue squeue_create();
int enqueue(pSqueue sq,data_t value);
data_t dequeue(pSqueue sq);
int queue_empty(pSqueue sq);
int queue_full(pSqueue sq);
int queue_clear(pSqueue sq);
pSqueue queue_free(pSqueue sq);
		
