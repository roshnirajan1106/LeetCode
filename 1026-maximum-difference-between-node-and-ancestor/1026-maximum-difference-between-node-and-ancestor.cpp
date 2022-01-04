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
    void soln(TreeNode* root, int maximum, int minimum, int &ans)
    {
        if(root== NULL)
            return ;
        maximum = max(maximum,root->val);
        minimum = min( minimum, root->val);
        ans = max(ans , maximum - minimum);
        soln(root->left, maximum, minimum, ans);
        soln(root->right, maximum, minimum, ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        int maximum = INT_MIN;
        int minimum = INT_MAX;
        int ans = 0;
        soln(root, maximum, minimum, ans);
        return ans;
    }
};