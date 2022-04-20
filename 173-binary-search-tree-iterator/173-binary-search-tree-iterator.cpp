/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    queue<TreeNode*>q;
    TreeNode*curr ;
    void inorder(TreeNode*root)
    {   
        if(root == NULL)
            return ;
        inorder(root->left);
        q.push(root);
        inorder(root->right);
        
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        curr = q.front();
        q.pop();
        return curr->val;
    }
    
    bool hasNext() {
        return q.empty() == true ? false : true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */