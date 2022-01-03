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
    int countNodes(TreeNode* root) {
            if(root == NULL)
                return 0;
        int h_r = 1, h_l= 1;
        TreeNode *left = root;
        TreeNode *right =root;
        while(left->left != NULL)
        {
            h_l++;
            left = left->left;
        }
        while(right->right != NULL)
        {
            h_r ++;
            right = right->right;
        }
        if(h_l == h_r)
            return pow(2,h_l) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    
    }
};