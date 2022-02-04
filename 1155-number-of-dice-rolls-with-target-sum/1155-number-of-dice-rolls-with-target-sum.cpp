class Solution {
public:
    int mod = 1000000007;
    int count(int n, int target, int f , vector<vector<int>>&dp)
    {
        if(target == 0)
            return 1;
        if(n == 0)
            return 0 ;
        if(dp[n][target])
            return dp[n][target] - 1;
        
        for(int i = 1;i<=f;i++)
        {
            if(i <=target)
                dp[n][target] =(dp[n][target] + count(n-1,target-i,f,dp)) % mod;
        }
        dp[n][target] +=1;
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long int>>dp(n+1 , vector<long int >(target+1,0));
        dp[0][0] =1 ;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1; j<=target;j++)
            {
                for(int m = 1;m<=k && m<=j;m++)
                {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-m] % mod) %mod;
                }
            }
        }
        return dp[n][target];
    }
};