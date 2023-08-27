/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode * dummy = (struct ListNode *)malloc(sizeof(struct ListNode));//头结点
    dummy->next = head;
    struct ListNode * first = dummy;//指向头不是head
    struct ListNode * second = dummy;
    //双指针
    //first 领先 sec n+1个节点
    for (int i = 0; i < n + 1; i++)
        first = first->next;
     //printf("first %d",first->val);   
    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    printf("sec %d",second->val);
    second->next = second->next->next;

    return dummy->next;//返回head结点
}