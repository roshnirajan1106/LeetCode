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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*l =NULL;
        ListNode*prev =NULL;
        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val < list2->val)
            {
                if(l == NULL)
                {
                    l = new ListNode(list1->val);
                    prev = l;
                }
                    
                else{
                    ListNode* node = new ListNode(list1->val);
                    prev->next= node;
                    prev = node;
                }
                list1 = list1->next;
                    
            }
            else{
                if(l == NULL)
                {
                    l = new ListNode(list2->val);
                    prev = l;
                }
                    
                else{
                    ListNode* node = new ListNode(list2->val);
                    prev->next= node;
                    prev = node;
                }
                  list2 = list2->next;
            }
        }
        while(list1)
        {
            if(l == NULL)
                {
                    l = new ListNode(list1->val);
                    prev = l;
                }
                    
                else{
                    ListNode* node = new ListNode(list1->val);
                    prev->next= node;
                    prev = node;
                }
              list1 = list1->next;
        }
        while(list2)
        {
                 if(l == NULL)
                {
                    l = new ListNode(list2->val);
                    prev = l;
                }
                    
                else{
                    ListNode* node = new ListNode(list2->val);
                    prev->next= node;
                    prev = node;
                }
            list2 = list2->next;
        }
        return l;
    }
};