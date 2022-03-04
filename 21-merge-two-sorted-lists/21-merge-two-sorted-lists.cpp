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
    ListNode*merge(ListNode*l1, ListNode*l2)
    {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        ListNode*l;
        if(l1->val < l2->val)
        {
            l = new ListNode(l1->val);
            l->next = merge(l1->next,l2);
        }
        else
        {
            l = new ListNode(l2->val);
            l->next = merge(l1,l2->next);
        }
        return l;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge(list1,list2);
    }
};