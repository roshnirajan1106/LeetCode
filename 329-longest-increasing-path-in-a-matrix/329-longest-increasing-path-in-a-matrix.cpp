class Solution {
public:
    int dfs(int i,int j ,int m, int n, vector<vector<int>>& visited,vector<vector<int>>& dp, vector<vector<int>>& matrix,int p)
    {
        if(i > m-1 || j > n-1 || i<0 || j<0)
            return 0;
        if(visited[i][j] == 1)
            return 0;
        if(p != -1)
        {
            if(p >= matrix[i][j])
                return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        
        visited[i][j] = 1;
        int a = dfs(i+1,j, m,n, visited, dp, matrix, matrix[i][j]);
        int b = dfs(i,j+1, m,n, visited, dp, matrix, matrix[i][j]);
        int c = dfs(i,j-1, m,n, visited, dp, matrix, matrix[i][j]);
        int d = dfs(i-1,j, m,n, visited, dp, matrix, matrix[i][j]);
        visited[i][j] = 0;
        dp[i][j] =max(a,max(b,max(c,d))) + 1;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> dp(m, vector<int>(n,-1));
        int ans= 0;
        for(int i = 0 ;i < m ;i++)
        {
            for(int j = 0;j<n;j++)
            {
              ans = max(ans, dfs(i,j, m,n,visited, dp, matrix,-1)) ;
            }
        }
         return ans;
    }
};