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
    TreeNode * build(vector<int>& preorder, vector<int>& inorder,int &i,int s,int e)
    {
        
        if(s >e)
            return NULL;
        TreeNode * root = new TreeNode(preorder[i]);
        int j;
        for(j = s ; j<=e ;j++)
        {
            if(inorder[j] == preorder[i])
                break;
                
        }
        i++;
        root->left = build(preorder,inorder,i, s,j-1);
        root->right = build(preorder,inorder,i,j+1,e);
        return root;
        
        
        }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i =0;
        int s =0;
        int e = inorder.size() - 1;
        TreeNode *root = build(preorder,inorder ,i,s,e);
        return root;
    }
};