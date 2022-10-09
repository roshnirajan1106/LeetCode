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
    bool find(TreeNode*root,int k, map<int,int>&m)
    {
        if(root == NULL)
            return false;
        int target = k - root->val;
        if(m.find(target) !=  m.end())
        {
            return true;
            
        }
        m[root->val] = 1;
        bool left = find(root->left,k,m);
        bool right = find(root->right,k,m);
        return left || right;
    }
    bool findTarget(TreeNode* root, int k) {
        map<int,int>m;
        return find(root,k,m);
    }
};