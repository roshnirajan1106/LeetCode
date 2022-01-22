class Solution {
public:
    bool find(int n ,vector<int>&dp)
    {
        if(n == 0)
            return false;
        if(dp[n] != -1)
            return dp[n];
        bool ans = false ;
        for(int i = 1; i<=n&&  i*i <=n;i++)
        { 
                if(!find(n - i*i,dp))
                {
                    ans = true;
                    break;
                }
        }
        dp[n] = ans;
        return dp[n];
    }
    bool winnerSquareGame(int n) {
        vector<int>dp(100001,-1);
        return find(n,dp);
    }
};