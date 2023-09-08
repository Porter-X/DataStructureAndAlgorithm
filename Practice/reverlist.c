/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param head ListNode类 
 * @return ListNode类
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