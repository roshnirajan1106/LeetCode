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
    void soln(map<int,int>&parent, TreeNode*root,int p, int l, map<int,int> &level)
    {
        if(root == NULL)
            return ;
        parent[root->val] = p;
        level[root->val] = l;
        soln(parent, root->left, root->val,l+1, level);
        soln(parent, root->right, root->val,l+1, level);
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        map<int,int> parent;
        parent[root->val] = root->val;
        map<int,int> level;
        level[root->val] = 1;
        soln(parent, root,root->val, 0,level);
        if(level[x] == level[y] && parent[x]!= parent[y])
            return true;
        return false;
    }
};