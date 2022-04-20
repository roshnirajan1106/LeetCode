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
class Solution {
public:
    void inorder(TreeNode*root, stack<TreeNode*>&s)
    {
        if(root == NULL)
            return ;
        inorder(root->left,s);
        s.push(root);
        inorder(root->right,s);
    }
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*>s;
        inorder(root,s);
        int sum = 0;
        while(!s.empty())
        {
            TreeNode *top =s.top();
            s.pop();
            sum += top->val;
            top->val = sum;
            
        }
        return root;
    }
};