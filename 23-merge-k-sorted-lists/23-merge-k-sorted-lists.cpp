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
    ListNode*merge(ListNode *list1, ListNode*list2)
    {
        ListNode* head = NULL;
        ListNode*tail = NULL;
        ListNode*head1 =list1;
        ListNode* head2 = list2;
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        while(head1 != NULL && head2 !=NULL)
        {   
            if(head1->val < head2->val)
            {
                if(head == NULL)
                {
                    head = tail = new ListNode(head1->val);
                }
                else{
                    ListNode* node = new ListNode(head1->val);
                    tail->next = node;
                    tail = node;
                }
                head1 = head1->next;
            }
            else{
                if(head == NULL)
                {
                    head = tail = new ListNode(head2->val);
                }
                else{
                    ListNode* node = new ListNode(head2->val);
                    tail->next = node;
                    tail = node;
                }
                head2 = head2->next;
            }
            
        }
        while(head1 != NULL)
        {
             ListNode* node = new ListNode(head1->val);
                    tail->next = node;
                    tail = node;
            
            head1 = head1->next;
        }
         while(head2 != NULL)
        {
             ListNode* node = new ListNode(head2->val);
                    tail->next = node;
                    tail = node;
             
             head2= head2->next;
        }
        return head;
    
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        while(lists.size() > 1)
        {
            ListNode * node = merge(lists[0],lists[1]);
            lists.erase(lists.begin());
            lists.erase(lists.begin());
            lists.push_back(node);
        }
        return lists[0];
    }
};