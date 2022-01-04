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
//        vector<int> v(101,0);
//         v[0] = 1;
//         v[1] = 1;
//         queue<pair<TreeNode* , int>> q;
//         q.push({root, 1});
        queue<TreeNode*> q;
        q.push(root);
        bool pre = true;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL)
                pre = false;
            else{
                if(pre == false)
                    return false;
                q.push(node->left);
                q.push(node->right);
                    
            }
            
        }
        return true;
    }
};