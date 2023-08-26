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