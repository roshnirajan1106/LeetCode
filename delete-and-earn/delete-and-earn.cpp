class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        if(nums.size() == 1)
            return nums[0];
       int n = 10001;
        vector<int> dp(n,0);
        vector<int> sum(n,0);
        for(int i = 0;i<nums.size();i++)
        {
            sum[nums[i]] += nums[i];
        }
        dp[0] = 0;
        dp[1]  = sum[1];
        for(int i =2;i<n;i++)
            dp[i] = max(dp[i-1], dp[i-2] + sum[i]);
        
        return dp[n-1];
        
    }
    };