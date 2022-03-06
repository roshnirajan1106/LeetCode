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
    ListNode*reverseit(ListNode*node)
    {
        ListNode*prev = NULL;
        while(node != NULL)
        {
            ListNode*t = node->next;
            node->next=  prev;
            prev= node;
            node = t;
        }
        return prev;
    }
    ListNode*reverse(ListNode*head, int k)
    {
        ListNode *temp = head;
        ListNode * prev =NULL;

        int kk = k;
        while(temp != NULL && kk > 0)
        {
            ListNode*node = temp->next;
            temp->next = prev;
            prev = temp;
            temp = node;
            kk--;
        }
        if(temp != NULL)
            head->next = reverse(temp,k);
        if(temp ==  NULL && kk > 0)
            prev= reverseit(prev);
            
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
            return reverse(head,k);     
    }
};