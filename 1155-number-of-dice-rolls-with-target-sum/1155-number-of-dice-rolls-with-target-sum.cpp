class Solution {
public:
    int mod = 1000000007;
    int function(int n, int k, int t,vector<vector<int>> &dp)
    {
        if(t == 0 && n == 0)
        {
                return 1;
            
        }
        if( n==  0)
            return 0;
        if(t <=0)
            return 0;
        
        if(dp[n][t] != -1)
            return dp[n][t];
            
        int ans =0;
        for(int i =1;i<=k;i++)
        {
            ans = (ans +  function(n-1,k, t - i,dp)) %mod;
            
        }
        dp[n][t] = ans;
        return dp[n][t];
    }
    
    int numRollsToTarget(int n, int k, int target) {
        int cnt = 0;
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
         cnt = function(n, k, target,dp);
        return cnt;
    }
};