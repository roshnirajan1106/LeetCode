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
    TreeNode* build(int s, int e, vector<int>&preorder,vector<int>&inorder,int &pos)
    {
        
        if(s > e)
            return NULL;
        if(pos == preorder.size())
            return NULL;
        
        TreeNode* node = new TreeNode(preorder[pos]);
        
        int idx = 0;
        for(int j = s;j<=e;j++)
        {
            if(inorder[j] == preorder[pos])
            {
                idx = j;
                break;
            }
        }
        pos++;
        node->left = build(s,idx-1,preorder,inorder,pos);
        node->right = build(idx+1,e,preorder,inorder,pos);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int s= 0;
        int e = preorder.size()-1;
        int pos = 0;
        return build(s,e,preorder,inorder,pos);
    }
};