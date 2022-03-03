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
    vector<TreeNode*> helper(int n)
    {
        vector<TreeNode*> ans;
        if(n == 1)
        {
            ans.push_back(new TreeNode(0));
            return ans;
        }
        
        for(int i = 1;i<n;i+=2)
        {
            vector<TreeNode*>left = helper(i);
            vector<TreeNode*>right = helper(n-i-1);
            for(auto p : left)
            {
                for(auto q : right)
                {
                    TreeNode * node = new TreeNode(0);
                    node->left = p;
                    node->right =q;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*>ans;
        // if(n % 2 == 0)
        //     return ans;
        return helper(n);
    }
};