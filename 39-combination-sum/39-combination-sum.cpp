class Solution {
public:
    void dfs(vector<vector<int>> &res, vector<int> temp, int s, int sum ,int target, vector<int> &candidates)
    {
        if(sum == target)
        {
            res.push_back(temp);
            return;
        }
        if(sum > target)
            return ;
        if(s == candidates.size())
            return ;
        //inc 
        temp.push_back(candidates[s]);
        dfs(res,temp, s , sum +candidates[s], target, candidates);
        //exc
        temp.pop_back();
        dfs(res, temp,s+1, sum ,target ,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        dfs(res,temp,0,0, target,candidates);
        return res;
    }
};