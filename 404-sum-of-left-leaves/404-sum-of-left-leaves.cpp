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
    void find_sum(TreeNode*root,int &s,int num )
    {
        if(root == NULL)
            return ;
        if(root->left == NULL && root ->right == NULL && num == 1)
        {
            s = s + root->val;
            return;
        }
        find_sum(root->left,s,1);
        find_sum(root->right,s,0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int  s = 0;
        int num = 0;
        find_sum(root,s,num);
        return s;
    }
};