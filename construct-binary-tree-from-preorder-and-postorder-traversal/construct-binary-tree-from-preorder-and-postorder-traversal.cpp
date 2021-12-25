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
    TreeNode * build(vector<int>& preorder, vector<int>& postorder,int &i,int s,int e)
    {
        if(i < 0)
            return NULL;
        if(s > e)
            return NULL;
        
        TreeNode *root = new TreeNode(postorder[i]);
        int j;
    
        for(j = s ; j<=e && i >0;j++)
        {
            if(preorder[j] == postorder[i-1])
                break;
        }
        i--;
        root->right = build(preorder,postorder,i,j,e);
        root->left = build(preorder,postorder,i,s+1,j-1);
        return root;
            
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int s = 0;
        int i = preorder.size()-1;
        int e = preorder.size()-1;
        TreeNode* root = build(preorder,postorder, i, s, e);
        return root;
    }
}; 