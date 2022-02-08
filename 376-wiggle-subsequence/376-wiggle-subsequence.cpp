class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int>dp(nums.size() , 1);
        vector<int>flag(nums.size(),3);
        int n = nums.size();
        if(n == 1)
            return 1;
        
        int i = 1;
        while(i<n && nums[i] == nums[i-1])
            i++;
        if(i == n)
            return 1;
        
        int ans = 0;
        for(int j = i ;j<n;j++)
        {
            for(int k = 0; k<j;k++)
            {
                int diff = nums[j] - nums[k];
                if(diff == 0)
                    continue;
                if(flag[k] == 3)
                {
                    if(dp[j] < dp[k] + 1)
                    {
                        dp[j] = dp[k] +1;
                        if(diff > 0)
                            flag[j] = 1;
                        else
                            flag[j] = 2;
                    }
                
                }
                    
                else if(flag[k] == 2 && diff > 0 )
                { 
                    if(dp[j] < dp[k] + 1)
                    {
                        dp[j] = dp[k]  + 1;
                        flag[j] = 1;
                    }
                }
                else if( flag[k] == 1 && diff < 0)
                {
                     if(dp[j] < dp[k] + 1)
                     {
                         dp[j] = dp[k] + 1;
                         flag[j] = 2;
                     }
                    
                }
                
            }
            ans=  max(ans,dp[j]);
        }
        return ans;
    }
};