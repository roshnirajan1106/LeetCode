class Solution {
public:
   
    int combinationSum4(vector<int>& nums, int target) {
        vector<long int>dp(target+1,0);
        dp[0] =1;
        for(int i = 1;i<=target;i++)
        {   int x =0;
            for(int j = 0 ;j<nums.size();j++)
            {   
                if(i >= nums[j])
                    x += dp[i-nums[j]];
            }
         dp[i] = x;
        }
        int ans = dp[target];
        return ans;
    }
};