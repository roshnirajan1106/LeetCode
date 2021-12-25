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
    int find_height(TreeNode*root)
    {
        if(root == NULL)
            return 0;
        
        return max(find_height(root->left), find_height(root->right) ) +1;
    }
    TreeNode* ancestor(TreeNode*root,int level, int l)
    {
        if(root== NULL)
            return NULL;
        if(l == level)
            return root;
        TreeNode*left = ancestor(root->left, level,l+1);
        TreeNode*right = ancestor(root->right, level, l+1);
        if(left != NULL && right != NULL)
            return root;
        if(left == NULL && right != NULL)
        {
            return right;
        }
        return left;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int height = find_height(root);
        
        int l = 1;
        return ancestor(root, height, l);
    }
};