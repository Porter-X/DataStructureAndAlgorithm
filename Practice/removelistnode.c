/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode * dummy = (struct ListNode *)malloc(sizeof(struct ListNode));//ͷ���
    dummy->next = head;
    struct ListNode * first = dummy;//ָ��ͷ����head
    struct ListNode * second = dummy;
    //˫ָ��
    //first ���� sec n+1���ڵ�
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

    return dummy->next;//����head���
}