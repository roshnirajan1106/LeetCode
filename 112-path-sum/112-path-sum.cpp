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
    bool pathSum(TreeNode*root, int sum, int targetSum)
    {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL)
        {
            sum += root->val;
            if(sum == targetSum)
                return true;
            else
                return false;
            sum -= root->val;
            
        }
        
        
        
        bool left = pathSum(root->left,sum + root->val ,targetSum);
        bool right = pathSum(root->right,sum + root->val ,targetSum);
        return left || right;
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        return pathSum(root,0,targetSum);
    }
};