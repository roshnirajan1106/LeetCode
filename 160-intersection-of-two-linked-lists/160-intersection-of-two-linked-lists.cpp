/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int find_length(ListNode*head)
    {
        if(head == NULL )
            return 0;
        return 1  + find_length(head->next);
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1= find_length(headA);
        int len2 = find_length(headB);
        if(len1 > len2)
        {
            int x = len1 - len2;
            while(x--)
                headA = headA->next;
            
        }
        else
        {
            int x = len2 -len1;
            while(x--)
            {
                headB= headB->next;
            }
        }
        while(headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};