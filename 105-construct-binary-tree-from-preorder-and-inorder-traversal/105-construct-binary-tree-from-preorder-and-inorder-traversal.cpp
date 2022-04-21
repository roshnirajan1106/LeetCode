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
    TreeNode * build(vector<int>& preorder, vector<int>& inorder,int s, int e, int &pos)
    {
        if(s > e)
            return NULL;
        
        TreeNode*root = new TreeNode(preorder[pos]);
        int i ;
        for(i = s; i<=e;i++)
        {
            if(preorder[pos] == inorder[i])
                break;
        }
        pos ++;
        root->left = build(preorder,inorder,s,i-1,pos);
        root->right = build(preorder,inorder,i+1,e,pos);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int s = 0;
        int e = inorder.size()-1;
        int pos = 0;
        return build(preorder,inorder,s,e,pos);
        
    }
};