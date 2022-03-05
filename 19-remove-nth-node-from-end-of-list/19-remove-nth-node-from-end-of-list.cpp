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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      
        ListNode*prev = head;
        
        ListNode *temp = head;
        int m = length(head);
        int num = m - n;
       
        while(num)
        {
            prev = temp;
            temp= temp->next;
            num--;
        }
        if(temp == head)
        {
            head = head->next;
            delete temp;
            return head;
        }
        
        prev->next = temp->next;
        delete temp;

        return head;
    }
};