#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode * p = list1;
    struct ListNode * q = list2;
    struct ListNode dummy;
    struct ListNode * temp = &dummy;
    while (q != NULL && p != NULL)
    {
        temp = q->next;
        if (temp == NULL )
            break;
        while (p->val >= q->val && p->val <= temp->val)
        {            
            q->next = p;
            p = p->next;
            q = q->next;
            //printf("list test:%d\n",q->val);
        }
        q->next = temp;
        q = q->next;
    printf("list test:%d\n",q->val);
    printf("list test:%d\n",p->val);
    }
    

    return q;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    struct ListNode dummy;
    struct ListNode * tail = &dummy;// struct ListNode * tail = (struct ListNode *)malloc(sizeof (struct ListNode));
    struct ListNode * head = tail;//保存head指针位置
    
    if (list1 == NULL && list2 == NULL)
        return NULL;
    while (list1 != NULL && list2 != NULL)// 为空时退出循环
    {
        if (list1->val < list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
        printf("list val %d",tail->val);
    }

    while (list1 != NULL)
    {
        tail->next = list1;
        list1 = list1->next;
        tail = tail->next;
    }
    while (list2 != NULL)
    {
        tail->next = list2;
        list2 = list2->next;
        tail = tail->next;
    }

    return head->next;
}