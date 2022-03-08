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
    void print(ListNode*head)
    {
        while(head)
        {
            cout<<head->val;
            cout<<endl;
            head = head->next;
        }
    }
    ListNode*reverse(ListNode*head, ListNode*tail,ListNode*prev)
    {
        tail->next = NULL;
        while(head != NULL)
        {
            ListNode*node = head->next;
            head->next = prev;
            prev = head;
            head = node;
            
        }
       // print(tail);
        return tail;
    }
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        int i = 0;
        ListNode*left = NULL;
        ListNode*prev = NULL;
        ListNode*right = NULL;
        ListNode*temp = head;
        while(temp )
        {
            if(i == l-1)
            {
                left = temp;
                break;
            }
                
            prev = temp;
            temp = temp->next;
            i++;
        }
        
        temp =head;
        i = 0;
        while(temp)
        {
            if(i ==r-1 ){
                right = temp;
                break;
            }
                
            
            temp = temp->next;
            i++;
        }
        ListNode* nextNode = right->next;
       
        ListNode*node = reverse(left,right,nextNode);
        if(prev == NULL)
            return node;
        prev->next= node;
        return head;
        
    }
};