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
    
    bool isCompleteTree(TreeNode* root) {
       vector<int> v(101,0);
        v[0] = 1;
        v[1] = 1;
        queue<pair<TreeNode* , int>> q;
        q.push({root, 1});
        //q.push({NULL,1});
        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            int idx = q.front().second;
            q.pop();
            if(v[idx-1] == 0)
                return false;
            v[idx] = 1;
            if(node->left)
                q.push({node->left, 2*idx});
            if(node->right)
                q.push({node->right, 2*idx + 1});
        }
        return true;
    }
};