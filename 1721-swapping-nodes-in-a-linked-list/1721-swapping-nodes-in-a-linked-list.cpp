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
    int length(ListNode*temp)
    {
        if(temp == NULL)
            return 0;
        return 1 + length(temp->next);
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int n = length(head);
       
        ListNode*left= NULL, *right =NULL;
        ListNode*prev = NULL;
        ListNode*temp = head;
        int cnt =0;
        while(temp != NULL)
        {
            if(cnt == k-1)
            {
                left = temp;
                //prevf = prev;
            }
            if(cnt == n-k)
            {
                right = temp;
                cout<<"hey "<<cnt<<endl;
                
               // prevs = prev;
                
            }
            //prev = temp;
            temp = temp->next;
            cnt++;
            
        }
        //cout<<left->val<<" "<<right->val<<endl;
        swap(left->val,right->val);
        
        return head;
        
        
        
    }
};