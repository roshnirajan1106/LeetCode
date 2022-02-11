class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = 0;
        for(auto p : stones)
            totalSum +=p;
        
        int n = stones.size();
        vector<vector<bool>>dp(n+1,vector<bool>(totalSum+1,0));
        for(int i = 0; i<n+1;i++)
            dp[i][0] = 1;
        
        for(int i = 1;i<n+1;i++)
        {
            for(int j =1;j<totalSum+1;j++)
            {   
                bool inc = false;
                bool exc  = false;
                if(stones[i-1] <= j)
                {
                    inc = dp[i-1][j-stones[i-1]];
                }
                exc = dp[i-1][j];
                dp[i][j] = inc | exc;
            }
        }
        
        int ans = INT_MAX;
        for(int i = 0;i<totalSum+1;i++)
        {
            if(dp[n][i] == 1)
            {
                int diff = 2 * i - totalSum;
                diff = abs(diff);
                ans= min(ans, diff);
            }
        }
        return ans;
        
    }
};