/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*>m;
        map<Node*,Node*>m1;
        Node* newHead = NULL;
        Node *prev ;
        while(head != NULL)
        {
            Node* temp = new Node(0);
            
            temp->val = head->val;
            if(newHead == NULL)
                newHead = temp;
            else{
                prev->next = temp;

            }
            prev = temp;
            m[temp] = head;
            m1[head] = temp;
            head = head->next;
            
        }
        Node*temp = newHead;
        while(temp != NULL)
        {
            temp->random = m1[m[temp]->random];
            temp = temp->next;
        }
        return newHead;
    }
};