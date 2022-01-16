class Solution {
public:
    bool canPartition(vector<int>& nums) {
       
        int n = nums.size();
        
        int sum = 0;
        for(auto p : nums)
            sum +=p;
        
        if(sum & 1)
            return false;
        sum = sum/2;
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1,0));
        for(int i = 0 ; i <= n ; i ++)
        {
            dp[i][0] =1;
        }
        for(int i = 1; i< n + 1 ;i ++ )
        {
            for(int j = 1 ; j<= sum ;j++)
            {   int inc = false,exc=false;
                if(nums[i-1] <= j)
                    inc = dp[i-1][j- nums[i-1]];
                exc= dp[i-1][j];
             
                dp[i][j] = inc || exc;
            }
        }
        return dp[n][sum];
    }
};