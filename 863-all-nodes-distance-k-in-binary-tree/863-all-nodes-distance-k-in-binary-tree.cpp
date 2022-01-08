/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void print_at_level_l(TreeNode*root, vector<int> &v , int level, int l)
    {
        if(root == NULL)
            return ;
        if(level == l)
        {
            v.push_back(root->val);
            return ;
        }
        if(level < l)
            return ;
        print_at_level_l(root->left,v, level, l+1);
        print_at_level_l(root->right, v, level,l+1);
        return ;
        
        
    }
    int print_nodes_at_distance_k(TreeNode*root, vector<int> &v, int k,int target)
    {
        if(root == NULL)
            return -1;
        if(root->val == target)
        {
            print_at_level_l(root, v, k,0);
            return 0;
        }
        int left = print_nodes_at_distance_k(root->left, v, k, target);
        int right =print_nodes_at_distance_k(root->right, v, k, target);
        if(left == -1 && right == -1)
            return -1;
        else if(left != -1 )
        {
            if(left + 1 == k)
            {
                v.push_back(root->val);
                
            }
            else if(left + 2 <=k){
                print_at_level_l(root->right, v, k-2-left, 0);
            }
            return left + 1;
        }
        else{
            if(right + 1 == k)
            {
                v.push_back(root->val);
                
            }
            else if(right +2 <=k)
            {
                print_at_level_l(root->left, v, k-2-right, 0);
            }
            return right + 1;
        }
            
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res ;
        print_nodes_at_distance_k(root, res, k,target->val);
        return res;
    }
};