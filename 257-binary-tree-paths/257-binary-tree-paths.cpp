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
//     string convert(int val)
//     {
//         string res="";
        
//         if(val < 0)
//         {
//             flag=true;
//             val = val *-1;
//         }
//         while(val >0)
//         {
//             int rem = val % 10;
            
//             res = res + to_string(rem);
//             val = val/10;
//         }
//         reverse(res.begin(),res.end());
//         return res;
//     }
    void make(TreeNode*root,string s, vector<string>&res)
    {
        if(!root->left && !root->right)
        {
            s+= to_string(root->val);
            res.push_back(s);
            return ;
        }
        if(root == NULL)
            return ;
        
        s = s+ to_string(root->val) + "->";
        if(root->left)
            make(root->left,s ,res);
        if(root->right)
            make(root->right,s,res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        string s="";
        make(root,s,res);
        return res;
    }
};