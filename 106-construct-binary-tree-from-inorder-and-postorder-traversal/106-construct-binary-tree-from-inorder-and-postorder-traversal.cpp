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
    TreeNode* build(vector<int>&inorder,vector<int>&postorder,int s, int e, int &pos)
    {
        if(s > e)
            return NULL;
        TreeNode*root= new TreeNode(postorder[pos]);
        int i;
        for(i = s;i<=e;i++)
        {
            if(inorder[i] == postorder[pos])
                break;
        }
        pos  = pos - 1;
        root->right = build(inorder,postorder,i+1,e,pos);
        root->left = build(inorder,postorder,s,i-1,pos);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int s = 0;
        int e = n-1;
        int pos = n-1;
        return build(inorder,postorder,s,e,pos);
    }
};