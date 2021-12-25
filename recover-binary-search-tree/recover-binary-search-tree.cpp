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
   //IDEA FOR THIS SOLUTION IS , INORDER TRAVERSAL ALWAYS GIVES U A SORTED LIST
// SO FIND TWO PAIRS WHICH VOILATE THE CONDITION
// 1 4 3 2 5 6 7 , HERE 4 AND 2 ARE SWAPPED , TWO PAIRS WHICH VIOLATE THE CONDITION
// 4, 3 && 3,2 -> SWAP THE FIRST NODE OF FIRST PAIR WITH SECOND NODE OF SECOND PAIR
// 2, 3 3 ,4 
//IN CASE  WE GET 2 1 3 THEN SWAP 2 AND 1 , 
public:
    
    TreeNode*prev = NULL;
    TreeNode*first = NULL;
    TreeNode *second = NULL;
    void sol(TreeNode*root  )
    {
        if(root == NULL)
            return ;
        sol(root->left);
        if(first == NULL &&prev != NULL && prev->val >= root->val)  
        {
             first = prev; 
        }
        if(first != NULL && prev->val >= root->val)
            second = root;
        
        prev = root;
        
        sol(root->right);
            
    }
    void recoverTree(TreeNode* root) {
        
        sol(root);
       
        swap(first->val,second->val);
    }
};
