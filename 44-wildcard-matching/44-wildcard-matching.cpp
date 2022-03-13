class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
         if (n > 30000) return false;
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        for(int i = 0;i<=m;i++)
        {
            dp[i][0] = false;
        }
        for(int j = 0;j<=n;j++)
        {
            dp[0][j] = false;
        }
        dp[0][0] = true;
        for(int i = 1;i<=p.length();i++)
        {
            if(p[i-1] == '*')
                dp[0][i] = dp[0][i-1];
        }
        for(int i = 1;i<=m;i++)
        {
            for(int  j = 1;j<=n;j++)
            {
                if(p[j-1] >='a' && p[j-1]<='z' ||p[j-1]=='?')
                {
                    if(p[j-1] == s[i-1] || p[j-1] == '?')
                        dp[i][j]= dp[i-1][j-1];
                  
                }
                else{
                    
                    dp[i][j] =  dp[i][j-1] ||  dp[i-1][j]; 
                }
            }
        }
     
        return dp[m][n];
    }
};