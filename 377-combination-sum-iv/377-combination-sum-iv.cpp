class Solution {
public:
    int combination(vector<int>&nums,int target,vector<int>&dp)
    {
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;
        if(dp[target] != -1)
            return dp[target];
        int cnt = 0;
        for(int i = 0;i<nums.size();i++)
        {
            
            cnt += combination(nums,target-nums[i],dp);
        }
        return  dp[target] = cnt;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target +1 ,-1);
        return combination(nums,target,dp);
    }
};