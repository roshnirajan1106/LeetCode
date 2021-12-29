/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);
        if(root == NULL)
            return NULL;
        q.push(NULL);
        while(!q.empty())
        {
            Node *top = q.front();
            q.pop();
            
            if(top == NULL)
            {
                if(!q.empty())
                {
                    q.push(NULL);
                }
                    
            }
            
            else{
                if(q.front() == NULL )
                top->next = NULL;
                else
                top->next = q.front();
            
                
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
        }
        return root;
    }
};