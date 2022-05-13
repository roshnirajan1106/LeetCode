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
        queue<Node*>q;
        if(root== NULL)
            return NULL;
        q.push(root);
        Node*prev = NULL;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto top = q.front();
                q.pop();
                if(prev == NULL)
                {
                    //do nothing
                }
                else
                    prev->next = top;
                
                prev = top;
                
                
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
            if(prev)
            prev->next = NULL;
            prev = NULL;
        }
        return root;
    }
};