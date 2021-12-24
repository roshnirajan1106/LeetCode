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
    int h ;
    bool bal;
    Pair(){
        h = 0;
        bal = true;
    }
    
};
class Solution {
public:
    Pair balanced(TreeNode *root)
    {
        Pair p ;
        if(root == NULL)
            return p;
        
        if(root->left == NULL && root->right == NULL)
        {
            p.h= 1;
        
        }
        Pair left  = balanced(root->left);
        Pair right = balanced(root->right);
        
        p.h = max(left.h,right.h) + 1;
        int x = abs(left.h - right.h);
        if(left.bal && right.bal && x<=1)
        {
            p.bal=true;
        }
        else{
            p.bal= false;
            
        }
        return p;
        
    }
    bool isBalanced(TreeNode* root) {
        Pair p = balanced(root);
        return p.bal;
    }
};