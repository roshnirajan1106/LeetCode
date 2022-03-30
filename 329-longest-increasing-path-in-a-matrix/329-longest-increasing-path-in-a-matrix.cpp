class Solution {
public:
    int dfs(int i , int j,int m,int n,vector<vector<int>>&visited,vector<vector<int>>&matrix,int prev,vector<vector<int>>&dp)
    {
        if(i > m -1 || j >n -1 || i <0 || j <0)
            return 0;
        if(visited[i][j] == 1)
            return 0;
        if(prev >= matrix[i][j])
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        visited[i][j] = 1;
         prev = matrix[i][j];
        int a = dfs(i+1,j, m,n,visited,matrix,prev,dp);
        int b = dfs(i-1,j, m,n,visited,matrix,prev,dp);
        int c = dfs(i,j+1, m,n,visited,matrix,prev,dp);
        int d = dfs(i,j-1, m,n,visited,matrix,prev,dp);
        
        visited[i][j] = 0;
        return dp[i][j] = max(a,max(b,max(c,d)))  + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int prev = -1;
        int ans = 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                ans = max(ans, dfs(i,j,m,n,visited,matrix,prev,dp));
                
            }
        }
        return ans;
    }
};