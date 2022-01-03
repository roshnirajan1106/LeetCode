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
    TreeNode * prev = NULL;
    void build( TreeNode*root)
    {
        if(root == NULL)
            return ;
    
         TreeNode *temp = root->right;
        if(prev == NULL)
        {
            //temp = root->right;
            prev = root;
            build(root->left);
            build(temp);
        }
        else{
            //temp = root->right;
            prev->right = root;
            prev->left = NULL;
            prev = root;
            build(root->left);
            build(temp);
        }
        
        
       
    }
    void flatten(TreeNode* root) {
        build(root);
    }
};