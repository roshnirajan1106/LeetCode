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
    ListNode*merge(ListNode*l1,ListNode*l2)
    {
        if(l1 == NULL )
            return l2;
        if(l2 == NULL)
            return l1;
        
        ListNode* node = NULL;
        if(l1->val < l2->val)
        {
            node = new ListNode(l1->val);
            node->next = merge(l1->next,l2);
        }
        else{
            node = new ListNode(l2->val);
            node->next= merge(l1,l2->next);
        }
        return node;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        
        while(lists.size() > 1)
        {
            ListNode*node = merge(lists[0] ,lists[1] );
            lists.erase(lists.begin() );
            lists.erase(lists.begin() );
            lists.push_back(node);
        }
        return lists[0];
    }
};