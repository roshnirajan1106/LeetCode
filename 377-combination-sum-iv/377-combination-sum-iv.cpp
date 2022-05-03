class Solution {
public:
    int find(int i, int n, vector<int>&nums,int target,int &sum,vector<int>&dp)
    {
        
        if(sum == target)
            return 1;
        if(sum  > target || i == n)
            return 0;
        if(dp[sum] != -1)
            return dp[sum];
     int count = 0;   
    for(int i = 0;i<n;i++)
    {
        sum = sum + nums[i];
        count += find(i,n,nums,target,sum,dp);
        sum = sum -nums[i];
        
    }
    return dp[sum] =  count;
        
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        vector<int>dp(target + 1,-1);
        return find(0,n,nums,target,sum,dp);
    }
};