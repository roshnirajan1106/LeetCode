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
    int length(ListNode*l1)
    {
        if(l1 == NULL)
            return 0;
        return 1 + length(l1->next);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int m = length(l1);
        int n =length(l2);
        ListNode*head;
        int rem = 0;
        if(m > n)
        {
            head=l1;
            ListNode*prev; 
            while(l2!= NULL)
            {
                int sum = l1->val + l2->val + rem;
                l1->val = sum % 10;
                rem = sum/10;
                prev = l1;
                l1= l1->next;
                l2 = l2->next;
            }
            while(l1 != NULL)
            {
                int sum = l1->val + rem;
                l1->val = sum % 10;
                rem = sum /10;
                prev = l1;
                l1 = l1->next;
            }
            if(rem != 0)
            {
                ListNode*n = new ListNode(rem);
                prev->next = n;
            }
                
        }
        
        else{
            ListNode*temp = l1;
        l1 = l2;
        l2 = temp; 
            head=l1;
            ListNode*prev; 
            while(l2!= NULL)
            {
                int sum = l1->val + l2->val + rem;
                l1->val = sum % 10;
                rem = sum/10;
                prev = l1;
                l1= l1->next;
                l2 = l2->next;
            }
            while(l1 != NULL)
            {
                int sum = l1->val + rem;
                l1->val = sum % 10;
                rem = sum /10;
                prev = l1;
                l1 = l1->next;
            }
            if(rem != 0)
            {
                ListNode*n = new ListNode(rem);
                prev->next = n;
            }
        }
        return head;
        
    }
};