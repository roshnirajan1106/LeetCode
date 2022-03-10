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
    ListNode* add(ListNode*l1,ListNode*l2, int c)
    {
        if(l1 == NULL && l2 == NULL)
        {
                if( c== 0)
                    return NULL;
                return new ListNode(c);
        }
           
        int ans = c;
        if(l1)
        {
            ans += l1->val;
            l1 = l1->next;
        }
        if(l2)
        {
            ans += l2->val;
            l2 = l2->next;
        }
        
        int num =ans %10;
        ans = ans  / 10;
        ListNode *node = new ListNode(num);
        node->next = add(l1,l2,ans);
        return node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1,l2,0);
    }
};