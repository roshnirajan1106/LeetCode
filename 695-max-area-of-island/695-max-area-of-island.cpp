class Solution {
public:
    void dfs(vector<vector<int>>& visited,vector<vector<int>>& grid, int i, int j , int m, int n, int &cnt)
    {
        if(i > m-1 || j >n-1 || i<0 || j<0)
            return ;
        if(grid[i][j] == 0)
            return ;
        if(visited[i][j] == 1)
            return ;
        
        visited[i][j] = 1;
        cnt++;
         dfs(visited, grid, i +1,j, m, n, cnt);
         dfs(visited, grid, i -1,j, m, n, cnt);
         dfs(visited, grid, i,j+1, m, n, cnt);
         dfs(visited, grid, i,j-1, m, n, cnt);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m, vector<int>(n,0));
        int ans  = 0;
        int cnt = 0;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0 ;j<n;j++)
            {
                if(visited[i][j] == 0 && grid[i][j] == 1)
                {
                    
                    dfs(visited,grid, i,j,m,n, cnt);
                    ans = max(ans, cnt);
                    cnt =0;
                }
            }
        }
        return ans;
    }
};