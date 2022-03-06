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
        ListNode*prev = NULL;
        ListNode*temp = head;
        if(head == NULL)
            return NULL;
        ListNode*next =head->next;
        while(next != NULL)
        {   
            cout<<temp->val <<" "<<next->val<<endl;
            if(temp->val != next->val)
            {
                cout<<"Inside"<<endl;  
                if(prev == NULL)
                {
                    prev  = temp;
                    
                    head  = prev;
                }
                else{
                    prev->next = temp;
                    prev = temp;
                }
                next = next->next;
                temp = temp->next;
                
            }
            else{
                
                while(next != NULL && temp->val == next->val )
                {
                    next = next->next;
                }
                
                temp = next;
                if(next == NULL)
                    break;
                next = next->next;
            }
        }
        if(prev != NULL)
        {
            prev->next  = temp;
        
            return head;
        }
        else{
            prev= temp;
            return prev;
        }
        
    }
};