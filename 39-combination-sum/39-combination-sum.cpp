class Solution {
public:
    void find(vector<vector<int>>&ans,vector<int>&res,int i, int n ,vector<int>&candidates,int &sum,int &target){
        if(i == n)
        {
            return ;
        }
        if(sum == target)
        {
            ans.push_back(res);
            return ;
        }
        if(sum > target)
            return ;
        
        res.push_back(candidates[i]);
        sum = sum+candidates[i];
        find(ans,res,i,n,candidates,sum,target);
        sum = sum -candidates[i];
        res.pop_back();
        find(ans,res,i+1,n,candidates,sum,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>ans;
        int i = 0;
        int n = candidates.size();
        int sum = 0;
        find(res,ans,i,n,candidates,sum,target);
        return res;
    }
};