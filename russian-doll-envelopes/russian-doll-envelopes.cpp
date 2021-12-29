class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
       sort(envelopes.begin(),envelopes.end());
        
        int n = envelopes.size();
        vector<int> dp(n,0);
        dp[0] =1;
        int res = 1;
        for(int i =1;i<n;i++)
        {   int ans = 0;
            for(int j = 0; j <i ; j ++ )
            {
               if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
               {
                    ans = max(ans, dp[j]);
               }
            }
         dp[i] = ans + 1;
         res = max(res,dp[i]);
        }
        return res;
    }
};