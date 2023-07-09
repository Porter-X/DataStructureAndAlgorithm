#ifndef __LINKQUEUE_H
#define __LINKQUEUE_H
#include "bitree.h"

typedef bitree * datatype;//出队入队的元素是二叉树节点指针

typedef struct node{
	datatype data;
	struct node *next;
}linknode, *linklist;

typedef struct {
	linklist front,rear;
}linkqueue;

linkqueue * queue_create();
int enqueue(linkqueue * lq, datatype value);
datatype dequeue(linkqueue *lq);
int queue_empty(linkqueue *lq);
int queue_clear(linkqueue *lq);
linkqueue * queue_free(linkqueue *lq);
#endif