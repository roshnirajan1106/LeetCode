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
    
    
    void find_soln(TreeNode*root,map<int, priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > >&m , int row, int col )
    {
        if(root == NULL)
            return ;
        m[col].push(make_pair(row, root->val));
        find_soln(root->left, m, row +1 , col-1);
        find_soln(root->right, m, row +1 , col+1);
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int, priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > >m;
        // first int -> column, priority queue to store the row , value
        int row= 0 , col = 0 ;
        find_soln(root, m, row, col);
        for(auto p : m)
        {
            vector<int> v;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq = p.second;
            while(!pq.empty())
            {
                v.push_back(pq.top().second);
                pq.pop();
            }
            res.push_back(v);
        }
        return res;
        
    }
};