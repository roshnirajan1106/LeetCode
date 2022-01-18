class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length();
        int n = s.length();
        vector<vector<unsigned int>> dp(m+1, vector<unsigned int>(n+1,0));
            int k = 1;
            //long long unit = 1;
            for(int j = 1 ;j<n+1;j++)
            {
                if(t[k-1] == s[j-1])
                    dp[k][j] = dp[k][j-1] + 1 ;
                else
                    dp[k][j] = dp[k][j-1];
            }
    
        for(int  i= 2;i< m+1;i++)
        {
            for(int j = 1;j<n+1;j++)
            {
                if(t[i-1] == s[j-1])
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        int ans = dp[m][n];
        return ans;
    }
};