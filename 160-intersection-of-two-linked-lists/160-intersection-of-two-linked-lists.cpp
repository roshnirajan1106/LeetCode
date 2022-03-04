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
    int length(ListNode * l)
    {
        if(l == NULL)
            return 0;
        return 1 + length(l->next);
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = length(headA);
        int n =length(headB);
        if(m > n)
        {
            while(m-- != n)
                headA = headA->next;
        }
        else{
            while( m != n--)
                headB = headB->next;
        }
        while(headA != headB)
        {
            headA= headA->next;
            headB= headB->next;
        }
        return headA;
    }
};