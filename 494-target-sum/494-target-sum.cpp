class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int zeros = 0;
        for(int i = 0;i<nums.size();i++)
        {
            sum += nums[i];
            if(nums[i] == 0)
                zeros++;
        }
        sum += target;
        if(sum < 0)
            return 0;
        if(sum % 2 != 0)
            return 0;
        sum = sum /2;
        int n = nums.size();
        vector<int>dp(sum+1,0);
        dp[0] = 1;
        for(auto num : nums)
        {
            for(int s= sum; s>=num;s--)
            {
                dp[s] += dp[s-num];
            }
        }
        return dp[sum];
    }
};