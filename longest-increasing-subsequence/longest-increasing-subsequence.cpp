class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n,0);
        dp[0] =1;
        int res = 1;
        for(int i = 1 ;i<n;i++)
        {   int ans = 0;
            for(int j = 0 ;j <i ;j++)
            {
                if(a[i] > a[j])
                    ans = max(ans, dp[j]);
            }
            dp[i] = ans + 1;
            res =max(res, dp[i]);
         
        }
    
    return res;
    }
};