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
    TreeNode* soln(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        if(original == NULL)
            return NULL;
        if(original == target )
            return cloned;
       TreeNode*left =  soln(original->left, cloned->left, target);
        TreeNode * right = soln(original->right, cloned->right, target);
        if(left == NULL && right == NULL)
            return NULL;
        if(left == NULL && right != NULL)
            return right;
        return left;
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
       return soln(original, cloned, target);
    }
};