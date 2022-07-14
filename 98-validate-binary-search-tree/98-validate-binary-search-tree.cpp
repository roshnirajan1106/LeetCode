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
    bool valid(TreeNode*root,TreeNode*min,TreeNode*max)
    {
        if(root == NULL)
            return true;
        
        if((min == NULL || min->val < root->val)  && (max == NULL || max->val > root->val))
            return valid(root->left,min,root) && valid(root->right,root,max);
        
        
        return false;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode * min = NULL;
        TreeNode *max = NULL;
        return valid(root,min,max);
    }
};