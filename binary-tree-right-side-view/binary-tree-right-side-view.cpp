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
    void rightView(map<int,int> &m, int level, TreeNode*root)
    {
        if(root == NULL)
            return ;
        if(m.find(level) ==m.end())
        {
            m[level] = root->val;
        }
        rightView(m, level+1,root->right);
        rightView(m, level+1,root->left);
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> m;
        vector<int> res;
        
        int level = 0;
        rightView(m,level,root);
        for(auto p : m)
        {
            res.push_back(p.second);
        }
        return res;
    }
};