/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 * 
 * @param head ListNode�� 
 * @return ListNode��
 */
struct ListNode* ReverseList(struct ListNode* head ) {
    // write code here
    struct ListNode dummy;
    struct ListNode* p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    dummy.next = p;

    printf(" val :%d\n", dummy.next->val);
    struct ListNode* temp1 = head;
    struct ListNode* temp2 = head->next;
    temp1->next = NULL;
    while (head->next != NULL)
    {
        head = head->next;
        
        temp2->next = head;
        temp1 = head;
        temp2 = head->next; 
    }
    return NULL;
}