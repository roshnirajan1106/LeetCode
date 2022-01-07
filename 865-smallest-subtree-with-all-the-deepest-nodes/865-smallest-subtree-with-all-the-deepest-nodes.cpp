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
    pair<TreeNode* , int>  soln(TreeNode *root)
    {
        pair<TreeNode* , int> p;
        if(root == NULL)
        {
            p.first = NULL;
            p.second = 0;
            return p;
        }
        if(root->left == NULL && root->right == NULL)
        {
            p.first = root;
            p.second = 1;
            return p;
        }
        pair<TreeNode* , int> left = soln(root->left);
        pair<TreeNode* , int> right = soln(root->right);
        
        if(left.second == right.second )
        {
            p.first = root;
            p.second = left.second + 1;
    
        }
        else if( left.second > right.second  )
        {
            p.first = left.first;
            p.second = 1 + left.second;
        }
       else
       {
            p.first = right.first;
            p.second = 1 + right.second;
        }
        return p;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<TreeNode*, int> res;
        res = soln(root);
        return res.first;
    }
};