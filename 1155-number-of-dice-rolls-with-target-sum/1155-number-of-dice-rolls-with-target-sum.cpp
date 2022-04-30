class Solution {
public:
    int mod = 1000000007;
    int ways(int n,int k, vector<vector<int>>&dp,int target,int &sum)
    {
        if(n == 0 && sum == target)
            return 1;
        if(n == 0)
            return 0;
        if(sum  > target)
            return 0;
        if(dp[n][sum] != -1)
            return dp[n][sum];
        int count = 0;
        for(int i = 1;i<=k;i++)
        {
            sum = sum + i;
            count = (count + ways(n-1,k,dp,target,sum)) % mod;
            sum = sum -i;
        }
        return dp[n][sum] = count;
        
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int sum  = 0;
        return ways(n,k,dp,target,sum);
    }
};