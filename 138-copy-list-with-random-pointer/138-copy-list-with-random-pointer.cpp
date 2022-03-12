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
        Node*newHead = NULL;
        Node*prev  = NULL;
        Node *temp = head;
        while(head)
        {
            if(newHead == NULL)
            {
                newHead = new Node(head->val);
                prev = newHead;
                m[head] = newHead;
            }
            else{
                Node * node = new Node(head->val);
                prev->next = node;
                prev = node;
                m[head] = node;
            }
            head = head->next;
        }
        Node* Head = newHead;
        while(temp)
        {
            Node*x = m[temp->random];
           
            Head->random = x;
            
            Head = Head->next;
            temp = temp ->next;
            
        }
        return newHead;
        
    }
};