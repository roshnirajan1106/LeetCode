class Solution {
public:
    int find(int i ,int j,vector<vector<int>>& matrix,int m,int n,vector<vector<int>>&dp)
    {
        if(i == m)
            return 0;
        if(i > m || j > n-1 || i< 0 || j < 0)
            return INT_MAX;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans1 =find(i+1,j-1,matrix,m,n,dp);
        int ans2 = find(i+1,j,matrix,m,n,dp);
        int ans3= find(i+1,j+1,matrix,m,n,dp);
    
        int ans = min(ans1,min(ans2,ans3));
        if(ans == INT_MAX)
            return dp[i][j] = INT_MAX;
        
        return dp[i][j] =  matrix[i][j] + ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int m = matrix.size();
        int n =matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i = 0;i<n;i++)
        {
            
            int res = find(0,i,matrix,m,n,dp);
            if(res == INT_MAX)
                continue;
            
            int sum =  res;
            
            ans = min(ans,sum);
        }
        return ans;
    }
};