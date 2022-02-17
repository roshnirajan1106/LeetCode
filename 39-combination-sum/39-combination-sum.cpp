class Solution {
public:
    void dfs(vector<int>ans,vector<vector<int>>&res,int i,int n,int sum ,int target,vector<int>& candidates)
    {
        if(i == n)
            return ;
        if(sum > target)
            return ;
        if(sum == target)
        {
            res.push_back(ans);
            return ;
        }
        //include
        ans.push_back(candidates[i]);
        dfs(ans,res,i,n,sum +candidates[i],target,candidates);
        ans.pop_back();
        dfs(ans,res,i+1,n,sum,target,candidates);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>ans;
        int n = candidates.size();
        dfs(ans,res,0,n,0,target,candidates);
        return res;
    }
};