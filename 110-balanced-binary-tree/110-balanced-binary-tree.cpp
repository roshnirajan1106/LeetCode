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
class node{
    public:
    bool balanced;
    int height ;
};
class Solution {
public:
    node  balanced(TreeNode*root)
    {
        node n ;
        if(root== NULL)
        {
            n.height = 0;
            n.balanced= true;
             return n ;
            
        }
           
        node left = balanced(root->left);
        node right = balanced(root->right);
        if(abs(left.height-right.height) <=1 && left.balanced && right.balanced && balanced(root->left).balanced && balanced(root->right).balanced){
            n.height = max(left.height,right.height) + 1;
            n.balanced= true;
            return n;
        }
        n.height = max(left.height,right.height) + 1;
        n.balanced = false;
        return n;
    }
    bool isBalanced(TreeNode* root) {
        node n = balanced(root);
        return n.balanced;
    }
};