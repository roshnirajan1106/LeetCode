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
    vector<int> soln(int &cnt, TreeNode*root, int d)
    {   
        vector<int> res(11, 0);
        if(root == NULL)
        {
            return res;
        }
        if(root->left == NULL && root->right == NULL)
        {
            res[1]++;
            return res;
        }
        vector<int> left = soln(cnt, root->left, d);
        vector<int> right = soln(cnt, root->right, d);
        
        for(int i = 1 ;i<11 ;i++)
        {
            for(int j = 1; j<11;j++)
            {
                if(i + j <= d)
                    cnt += left[i]*right[j];
            }
        }
        for(int i = 0 ;i<10;i++)
        {
            res[i+1] = left[i] + right[i];
        }
        return res;

    }
    int countPairs(TreeNode* root, int distance) {
        int cnt = 0;
        soln(cnt, root, distance);
        return cnt;
    }
    
};