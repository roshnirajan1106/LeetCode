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
    void decimal(ListNode*head, int &pow,int &ans)
    {
        if(head == NULL)
            return ;
        decimal(head->next, pow,ans);
        if(head->val == 1)
        {
            int num = 1<<pow;
            ans += num;
            
        }
        pow= pow+1;
            
        
        
    }
    int getDecimalValue(ListNode* head) {
        int ans =0;
        int pow = 0;
         decimal(head,pow,ans);
        return ans;
    }
};