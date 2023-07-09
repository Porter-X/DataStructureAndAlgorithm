#include <iostream>
#include "blinkqueue.c"
#include "bitree.h" 

using namespace std;


data_t ch;

bitree *bitree_create()
{
    bitree *r;
    cin>>ch;
    if (ch == '#')
        return NULL;
    if((r = (bitree *)malloc(sizeof(node))) == NULL)
    {
        return NULL;
    }
    r->data = ch;
    r->lnode = bitree_create();
    r->rnode = bitree_create();

    return r;

}

void layerout(bitree *r)
{
    linkqueue *lq;
    lq = queue_create();
    if (r == NULL)
        return ;
    cout<<r->data<<" ";
    enqueue(lq, r);
    while (!queue_empty(lq))
    {
        r = dequeue(lq);
        if (r->lnode != NULL)
        {
            cout<<r->lnode->data<<" ";
            enqueue(lq, r->lnode);
        }
        if (r->rnode != NULL)
        {
            cout<<r->rnode->data<<" ";
            enqueue(lq, r->rnode);
        } 

    }    
}

void bitree_preorder(bitree *r)
{
    if (r == NULL)
        return ;
    cout<<r->data<<" ";
    bitree_preorder(r->lnode);
    bitree_preorder(r->rnode);
}

//AB#CD###E#FGH##K###
int main(int argc, char const *argv[])
{
    /* code */
    bitree *r;

    r = bitree_create();

    bitree_preorder(r);
    puts("");
    layerout(r);
    return 0;
}
