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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        
        vector<vector<int>>ans;
        vector<int>arr;
        if(root == NULL)
            return ans;
        while(!q.empty())
        {
            int size = q.size();
            vector<int>res;
            while(size > 0)
            {
                auto top = q.front();
                q.pop();
                size--;
                res.push_back(top->val);
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
                
            
            }
            ans.push_back(res);
       }
        return ans;
    }
};