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
class Pair{
    public:
    int height;
    bool balanced;
    Pair(){
        height = 0;
        balanced = true;
    }
};
class Solution {
public:
    Pair balance(TreeNode*root)
    {
        Pair p;
        if(root == NULL)
            return p;
        Pair left = balance(root->left);
        Pair right = balance(root->right);
        if(abs(left.height- right.height) <= 1 && left.balanced && right.balanced)
            p.balanced = true;
        else
            p.balanced = false;
        
        p.height = max(left.height,right.height) + 1;
        return p;
    }
    bool isBalanced(TreeNode* root) {
        Pair p = balance(root);
        return p.balanced;
    }
};