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
    void cal(TreeNode*root, int targetSum, int& s,vector<int>&v,vector<vector<int>>&sum)
    {
        if(root == NULL)
            return ;
        if(root->left == NULL && root->right == NULL && (s+ root->val) == targetSum)
        {
            v.push_back(root->val);
            sum.push_back(v);
            v.pop_back();
            return;
        }
    
        
        
        s = s + root->val;
        v.push_back(root->val);
        cal(root->left,targetSum,s,v,sum);
        cal(root->right,targetSum,s,v,sum);
        v.pop_back();
        s = s- root->val;
        
        return ;
        
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        vector<int>v;
        int s  = 0;
        cal(root,targetSum,s,v,res);
        return res;
    }
};