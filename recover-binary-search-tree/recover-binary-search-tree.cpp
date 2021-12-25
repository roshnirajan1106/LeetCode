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
    
    TreeNode*prev = NULL;
    TreeNode*first = NULL;
    TreeNode *second = NULL;
    void sol(TreeNode*root  )
    {
        if(root == NULL)
            return ;
        sol(root->left);
        if(first == NULL &&prev != NULL && prev->val >= root->val)  
        {
             first = prev; 
        }
        if(first != NULL && prev->val >= root->val)
            second = root;
        
        prev = root;
        
        sol(root->right);
            
    }
    void recoverTree(TreeNode* root) {
        
        sol(root);
       
        swap(first->val,second->val);
    }
};