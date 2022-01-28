class Solution {
public:

    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n =matrix[0].size();
        
        vector<vector<int>>dp(m+1, vector<int>(n+1,0));
        for(int i =1;i<m+1;i++)
        {
            for(int j = 1;j<n+1;j++)
            {
                if(matrix[i-1][j-1] == '1')
                {
                    dp[i][j] = min(dp[i-1][j],min(dp[i][j-1], dp[i-1][j-1])) +1;
                    ans = max(ans, dp[i][j]);
                    
                }
            }
        }
        return ans *ans;
        
    }                                                                        
};