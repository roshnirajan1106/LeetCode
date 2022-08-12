/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowest(TreeNode*root, TreeNode*p , TreeNode*q)
    {
        if(root == NULL)
            return NULL;
        if(root->val == p->val || root->val == q->val)
            return root;
        
        
        
        TreeNode*left = lowest(root->left,p,q);
        TreeNode*right = lowest(root->right,p,q);
        
        if(left == NULL && right == NULL)
            return NULL;
        if(left && right)
            return root;
        if(left)
            return left;
    
            return right;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
        return lowest(root,p,q);
    }
};