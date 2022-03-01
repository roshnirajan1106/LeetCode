class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);
        dp[0] = 0;
      
        for(int i = 1;i<=n;i++)
        {
            
            int num = i;
            int rbsum = num & -num;
            num = num - rbsum;
            dp[i] = 1 + dp[num];
            
            
            
        }
        return dp;
    }
};