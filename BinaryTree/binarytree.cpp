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
    if ('#' == ch)//�޺�������
        return NULL;    
    root = (bitree *)malloc(sizeof(bitree));
    if (NULL == root)
        return NULL;
    root->data = ch;
    root->lnode = bitree_create();//������������
    root->rnode = bitree_create();

    return root;
}

void preorder(bitree *r)//�������
{
    if (r == NULL)
        return ;
    printf("%c ",r->data);//
    preorder(r->lnode);//���ڵ����������
    preorder(r->rnode);//��������
}

void inorder(bitree *r)//������� �� �� ��
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

void postorder(bitree *r)//�������� ������ ������ ����
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
