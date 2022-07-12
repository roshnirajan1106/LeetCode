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
    TreeNode* ancestor(TreeNode*root,TreeNode*p,TreeNode*q)
    {
        if(root == NULL)
            return NULL;
        if(root->val >=  p->val && root->val <=q->val)
            return root;
        if(root->val >= p->val && root->val >= q->val)
            return ancestor(root->left,p,q);
        
        return ancestor(root->right,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < q->val)
            return ancestor(root,p,q);
        return ancestor(root,q,p);
    }
};