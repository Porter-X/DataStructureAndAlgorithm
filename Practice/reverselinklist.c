#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}linknode,*linklist;

//��������
linklist ls_create()
{
    linklist ls;
    if (ls == NULL)
        return NULL;
    ls = (linklist)malloc(sizeof(linknode));//����Ľڵ�
    ls->data = 0;
    ls->next = NULL;

    return ls;    
}

//��������
int ls_insert(linklist ls, int data)
{
    linklist new;
    if (ls == NULL)
        return -1;    
    new = (linklist)malloc(sizeof(linknode));//����Ľڵ�        
    new->data = data;
    new->next = NULL;

    while (ls->next !=NULL)
    {
        ls = ls->next;
    }
    ls->next = new;

    return 0;
}

//��ӡ����
int ls_output(linklist ls)
{
    linklist p;
    if (ls == NULL)
        return -1; 
    p = ls;

    
    while (p->next != NULL)
    {
        p = p->next;
        printf("%d ",p->data);
    }      
    puts("");

}

//free ����
int ls_free(linklist ls)
{
    if (ls == NULL)
        return -1; 
    while (ls->next != NULL)
    {
        ls = ls->next;
        free(ls);
    }    
    return 0;
}

linklist get_ls_tail(linklist H)
{
    linklist p;
    if (H == NULL)
        return NULL;
    p = H->next;
    while (p->next != NULL)
        p = p->next;
    //printf("tail :%d ",p->data);
    return p;
}
/* int reversels(linklist H)
{
    linklist p;
    linklist q,t;
    if (H == NULL)
        return -1;
    linklist tail = get_ls_tail(H);
    p = H->next;
    while (H->next != tail)
    {
        q = p->next;//����ڶ����ڵ�
        //p->next = NULL;//�ÿպ��޷�Ѱ��β���
        t = get_ls_tail(H);//�ҵ�β���
        p->next = NULL;
        t->next = p;//�ı�β���
        H->next = q;
        p = H->next;
    }
    return 0;
} */

int reversels(linklist H)
{
    linklist p,q,temp,tmp2;
    if (H == NULL)
        return -1;
    linklist tail = get_ls_tail(H); 
    p = H->next;
    q = p->next;
    p->next = NULL;
    temp = q->next;
    q->next = p;
    while (temp !=NULL && temp->next !=q)
    {
        tmp2 = temp->next;
        temp->next = q;
        q = temp;
        temp = tmp2;//�޷�����ѭ��
    }
    H->next = tail;
    return 0;
}

//�򻯰�
linklist reverselinklist(linklist H)
{
    linklist current, pre, next;
    pre = NULL;
    current = H->next;
    next = NULL;
  while (current!= NULL) {
    next = current->next;
    current->next = pre;
    pre = current;
    current = next;
  }

  H->next= pre; // ��������ͷ�ڵ�

  return H;

}

int main(int argc, char const *argv[])
{
    linklist ls;
    ls = ls_create();//ls����ȥû��
    if (ls == NULL)
        return -1;
    ls_insert(ls, 10);
    ls_insert(ls, 20);
    ls_insert(ls, 30);
    ls_insert(ls, 40);
    ls_output(ls);
    //get_ls_tail(ls);
    //reversels(ls);
    //;
    ls_output(reverselinklist(ls));


    ls_free(ls);
    return 0;
}
