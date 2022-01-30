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
    long long  mod = 1000000007;
    
    long long findSum(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return root->val;
        return root->val + findSum(root->left) + findSum(root->right);
    }
    int find(TreeNode*root, long long &ans,long long sum)
    {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right== NULL)
            return root->val;
        int left = find(root->left, ans, sum);
        int right = find(root->right, ans, sum);
        ans = max(ans, max(left*(sum-left) ,right*(sum - right)));
        return left +right + root->val;
    }
    int maxProduct(TreeNode* root) {
        long long ans = 0;
        
        long long sum = findSum(root);
        find(root, ans,sum);
        return ans % mod;
    }
};