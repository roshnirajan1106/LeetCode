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
    
    bool isPalindrome(ListNode* head) {
        int len = length(head);
        ListNode*temp =head;
        stack<ListNode*>s;
        while(temp)
        {
            s.push(temp);
            temp =temp->next;
        }
        for(int i =0;i<len/2;i++)
        {
            if(head->val != s.top()->val)
                return false;
            s.pop();
            head = head->next;
                
        }
        return  true;
    }
    
};