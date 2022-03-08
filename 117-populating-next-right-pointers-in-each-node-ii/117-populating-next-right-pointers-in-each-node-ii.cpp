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
    void bfs(Node*&root)
    {
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            Node*prev = NULL;
            while(size--)
            {
                Node*top= q.front();
                q.pop();
                if(prev == NULL)
                    prev = top;
                else
                {
                    prev->next =top;
                    prev = top;
                }
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
            prev->next= NULL;
        }
        
    }
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
    
        bfs(root);
        return root;
    }
};