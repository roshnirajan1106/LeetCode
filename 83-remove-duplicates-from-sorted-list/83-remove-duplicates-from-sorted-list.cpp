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
        ListNode* ans = head;
        ListNode*prev = head;
        if(head == NULL)
            return head;
        head = head->next;
        while(head!= NULL)
        {
            if(prev->val == head->val)
            {
                ListNode*temp = head;
                while(head != NULL && head->val == temp->val)
                    head=head->next;
                
                prev->next = head;
                
            }
            else{
                prev= head;
                head=head->next;
            }
        }
        return ans;
    }
};