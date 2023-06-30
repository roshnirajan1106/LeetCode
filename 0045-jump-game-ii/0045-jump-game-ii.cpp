class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        if(nums.size() == 0 || nums.size() == 1) 
            return 0;
        
        for(int i = n-2;i>=0;i--)
        {
            if(nums[i] == 0 )
            {
               dp[i] = INT_MAX;
               continue;
            }
                
            int ans  = INT_MAX;
            for(int j = i+1;j<n && j<=nums[i] + i;j++)
            {
                ans = min(ans,dp[j]);
            }
            if(ans == INT_MAX)
                dp[i] = INT_MAX;
            else
                dp[i] = ans + 1;
            
        }
        for(int i = 0;i <dp.size();i++)
            cout<<dp[i]<<" ";
        return dp[0];
    }
};