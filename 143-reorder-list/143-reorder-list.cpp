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
        if(head == NULL)return 0;
        
        return 1 + length(head->next);
    }
    void reorderList(ListNode* head) {
        stack<ListNode*>s;
        ListNode*temp = head;
        while(temp)
        {
            s.push(temp);
            temp = temp->next;
        }
        int len = length(head);
        ListNode*ptr = head;
        for(int i = 0;i<len/2 && ptr;i++)
        {
            ListNode*node= s.top();
            s.pop();
            if(node != ptr)
                node->next = ptr->next;
            ptr->next = node;
            ptr = node->next;
        }
        
        ptr->next = NULL;
    }
};