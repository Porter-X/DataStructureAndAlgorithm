#include <iostream>
using namespace std;

typedef char data_t;

typedef struct node{
    data_t data;
    struct node *lnode, *rnode;
}bitree;

bitree *bitree_create()
{
    bitree *root;
    char ch;
    //scanf("%c",&ch);
    cin>>ch;
    if ('#' == ch)//无后继树标记
        return NULL;    
    root = (bitree *)malloc(sizeof(bitree));
    if (NULL == root)
        return NULL;
    root->data = ch;
    root->lnode = bitree_create();//先输入左子树
    root->rnode = bitree_create();

    return root;
}

void preorder(bitree *r)//先序遍历
{
    if (r == NULL)
        return ;
    printf("%c ",r->data);//
    preorder(r->lnode);//根节点后先左子树
    preorder(r->rnode);//后右子树
}

void inorder(bitree *r)//中序遍历 左 根 右
{
    if (r == NULL)
        return ;
    inorder(r->lnode);
    printf("%c ",r->data);
    inorder(r->rnode); 
/*     printf("%c ",r->lnode->data);
    inorder(r->lnode);
    if (r->rnode == NULL)
        return ;
    inorder(r->rnode); */
}

void postorder(bitree *r)//后续遍历 左子树 右子树 树根
{
    if (r == NULL)
        return ;
    postorder(r->lnode);
    postorder(r->rnode); 
    printf("%c ",r->data);    
}
int main(int argc, char const *argv[])
{
    /* code */
    bitree *root;
    root = bitree_create();
    preorder(root);
    puts("");
    inorder(root);
    puts("");
    postorder(root);
    return 0;
}
