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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        ListNode*node =NULL;
        ListNode*prev = NULL;
        ListNode*temp = head;
        ListNode*next = head->next;
        while(next)
        {
            if(temp->val != next->val)
            {
                if(prev == NULL)
                {
                    prev = temp;
                    node = temp;
                }
                else{
                    prev->next = temp;
                    prev= temp;
                    
                }
                next = next->next;
                temp = temp->next;
            }
            else{
                while(next && temp->val == next->val)
                    next = next->next;
                
                temp = next;
                if(next)
                next = next->next;
            }
        }
        if(prev)
            prev->next= temp;
        if(node == NULL)
            node = temp;
        return node;
    }
};