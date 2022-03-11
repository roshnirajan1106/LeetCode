/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int length(ListNode*head)
    {
        
        if(head == NULL)
            return 0;
        return 1 + length(head->next);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        int len = length(head);
        k = k %len;
        if(k == 0)
            return head;
        
        len = len-k;
        ListNode*prev = NULL;ListNode*temp = head;
        while(len--)
        {
            prev = temp;
            temp = temp->next;
            
        }
        prev->next = NULL;
        ListNode*temp1 = temp;
        while(temp1->next)
            temp1 = temp1->next;
        temp1->next = head;
        head = temp;
        return head;
        
    }
    
};