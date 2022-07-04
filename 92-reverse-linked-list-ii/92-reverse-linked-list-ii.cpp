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
    ListNode* reverse(ListNode*left,ListNode*right)
    {
        ListNode*prev = NULL;
        while(left != right)
        {
            ListNode*x = left->next;
            left->next= prev;
            prev = left;
            left = x;
        }
        left->next = prev;
        return left;
    }
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        ListNode*left = NULL;
        ListNode*right = NULL;
        ListNode*t = head;
        l--;
        ListNode*prev = NULL;
        ListNode*next = NULL;
        while(l--)
        {
            prev = t;
            t = t->next;
        }
        left = t;
        t = head;
        r--;
        while(r--)
        {
            t = t ->next;
            
        }
        right =t;
        next = t->next;
        ListNode * n = reverse(left,right);
        if(prev == NULL)
        {
            head = n;
            while(n ->next )
            {
                n = n->next;
            }
            n ->next = next;
        }
        else{
            prev->next = n;
            while(n ->next)
                n = n ->next;
            
            n->next = next;
        }
        return head;
    }
};