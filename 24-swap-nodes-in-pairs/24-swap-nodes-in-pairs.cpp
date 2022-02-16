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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode*node = head->next;
        ListNode*prev = head;
        head= head->next;
        while(head!= NULL)
        {
            ListNode*next = head->next;
            
            head->next = prev;
           
            prev->next = next;
            head= next;
        
        if(head == NULL || head->next == NULL)
            break;
        
        prev->next = head->next;
        prev = head;
        head = head->next;
           
      
        }
        return node;
    }
    
   
};