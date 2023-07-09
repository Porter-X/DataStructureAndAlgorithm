#ifndef __BITREE_H
#define __BITREE_H

typedef char data_t;

typedef struct t_node{
    data_t data;
    struct t_node *lnode;
    struct t_node *rnode;
}bitree;

#endif