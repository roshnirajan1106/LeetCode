class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        
        
        
        int total_sum = 0;
        for(int i = 0;i<n;i++)
            total_sum += stones[i];
        
        vector<int> dp(total_sum+1,0);
        dp[0] =1;
        for(int i = 0;i<n;i++)
        {
            for(int j = total_sum ; j>= stones[i];j--)
            {
                dp[j] |= dp[j - stones[i]];
            }
                
        }
        
        int min_len = INT_MAX;
        for(int i =1;i<=total_sum;i++)
        {   if(dp[i] == 1)
         {
             min_len = min(min_len , abs(2 *i - total_sum));
         }
           
        }
        return min_len;
    }
};