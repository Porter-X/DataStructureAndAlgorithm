/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *retArray = (int *)malloc(sizeof(int)*2);
    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                retArray[0] = i;
                retArray[1] = j;
            }

        }
    }
    *returnSize = 2;

    return retArray;
}

struct ListNode{
    int val;
    struct ListNode * next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
        struct ListNode* temp1;
        struct ListNode* temp2;
          temp1 = l1;
          temp2 = l2;        
        struct ListNode* pResult;
        struct ListNode* extraNode;
        int data = 0,flag = 0;
        struct ListNode * resultList = (struct ListNode *)malloc(sizeof(struct ListNode));//链表头指针指向头结点
        resultList->next = NULL;
        pResult = resultList;
        int carry = 0; //进位标志
        while (temp1 != NULL && temp2 != NULL)
        {
          data = temp1->val + temp2->val + carry;
          carry = data/10;
          printf("data: %d",data);


          pResult->val = data%10;
          //malloc a new node to save data
          struct ListNode* node= (struct ListNode *)malloc(sizeof(struct ListNode));
          node->next = NULL;
          extraNode = pResult;
          pResult->next = node;
          pResult = pResult->next;
          //l1 = l1->next;
          temp1 = temp1->next;
          temp2 = temp2->next;
        }
        puts("");
        while (temp1 != NULL)
        {
          pResult->val = (temp1->val + carry)%10; 
          printf("data2: %d",pResult->val);
          carry = (temp1->val + carry) /10;
          struct ListNode* node= (struct ListNode *)malloc(sizeof(struct ListNode));
          node->next = NULL;
          extraNode = pResult;
          pResult->next = node;
          pResult = pResult->next;
          temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
          pResult->val = (temp2->val + carry)%10; 
          printf("data2: %d",pResult->val);
          carry = (temp2->val + carry) /10;
          struct ListNode* node= (struct ListNode *)malloc(sizeof(struct ListNode));
          node->next = NULL;
          extraNode = pResult;
          pResult->next = node;
          pResult = pResult->next;
          temp2 = temp2->next;
        }        

        if (carry == 1)
        {
          pResult->val = 1;
        }
        else
        {
          extraNode->next = NULL;
          free(pResult);
        }


        return resultList;
}