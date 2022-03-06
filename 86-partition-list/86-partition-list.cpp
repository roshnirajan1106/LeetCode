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
    void  insert(ListNode*&head, int val)
    {
        if(head == NULL)
        {
            head = new ListNode(val);
            return ;
        }
             
        
        ListNode*temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        
        ListNode * node = new ListNode(val);
        temp->next= node;
    }
    ListNode* partition(ListNode* head, int x) {
       ListNode* l1 = NULL;
        ListNode*l2 =NULL;
        if(head == NULL)
            return head;
        while(head != NULL)
        {
            if(head->val < x)
            {
                insert(l1,head->val);
            }
            else{
                insert(l2, head->val);
            }
            head = head->next;
        }
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode *Temp = l1;
        while(Temp->next != NULL)
            Temp = Temp->next;
        Temp->next= l2;
        return l1;
    }
};