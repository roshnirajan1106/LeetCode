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
    void inorder(TreeNode*root,vector<TreeNode*>&res)
    {
        if(root == NULL)
            return ;
        inorder(root->left,res);
        res.push_back(root);
        inorder(root->right,res);
        
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>res;
        inorder(root,res);
        TreeNode*first = NULL;
        TreeNode*second = NULL;
        
        for(int i =1 ;i <res.size();i++)
        {
            if(res[i-1]->val > res[i]->val)
            {
                if(first ==NULL)
                {
                    first = res[i-1];
                    second= res[i];
                }
                else{
                    second = res[i];
                }
                    
            }
        }
        swap(first->val,second->val);
        
    }
};