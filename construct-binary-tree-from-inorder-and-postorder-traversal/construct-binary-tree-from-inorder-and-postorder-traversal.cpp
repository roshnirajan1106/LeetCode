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
    TreeNode*construct (int s ,int e, vector<int>& inorder, vector<int>& postorder,int n,int &i)
    {
       
        if( s > e  || i < 0)
            return NULL;
        TreeNode* root= new TreeNode(postorder[i]);
        int j;
        for(j = s;j<=e;j++)
        {
            if(postorder[i] == inorder[j])
                break;
        }
        i--;
        root->right = construct(j+1,e,inorder,postorder,n,i);
        root->left = construct(s,j-1,inorder,postorder,n,i);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        TreeNode* node = NULL;
        int n = inorder.size();
        if( n == 1)
        {
            node= new TreeNode(inorder[0]);
            return node;
        }
        int s = 0,e =n-1;
        int i= n-1;
        node = construct(s,e,inorder,postorder,n,i);
        return node ;
    }
};