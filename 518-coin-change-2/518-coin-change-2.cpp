class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        int  n =amount;
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int  i = 0 ; i < m + 1; i ++)
        {
            dp[i][0] = 1;
        }
        for(int i  =1;i<m+1;i++)
        {
            for(int j =1 ;j<n+1;j++)
            {   int inc = 0,exc = 0;
                if(coins[i-1] <= j )
                {
                    inc = dp[i][j-coins[i-1]];
                }
                exc = dp[i-1][j];
                dp[i][j]=inc + exc;
            }
        }
        
        return dp[m][n];
    }
};