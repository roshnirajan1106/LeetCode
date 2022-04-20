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
    void inorder(TreeNode*root,int &k,stack<int>&s)
    {
        if(root == NULL)
            return ;
        if(k == 0)
            return ;
        
        inorder(root->left,k,s);
        if(k > 0)
        s.push(root->val);
        k = k -1;
        inorder(root->right,k,s);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        stack<int>s;
        inorder(root,k,s);
        return s.top();
    }
};