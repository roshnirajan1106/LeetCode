class Solution {
public:
    void dfs(int i , int j, vector<vector<int>> &grid, vector<vector<int>> &visited,int m ,int n)
    {
        if( i < 0 || j < 0 || i > m -1 || j > n-1)
            return ;
        if(visited[i][j] == 1)
            return; 
        if(grid[i][j] == 1)
            return ;
        visited[i][j] = 1;
        
        grid[i][j] = 1;
        dfs(i+1, j, grid, visited, m ,n);
        dfs(i-1, j, grid, visited, m ,n);
        dfs(i, j+1, grid, visited, m ,n);
        dfs(i, j-1, grid, visited, m ,n);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        for(int i = 0;i<m;i++)
        {
            for(int j = 0; j<n;j++)
            {
                if(i == 0 ||j == 0 || i == m -1 || j == n-1)
                {  
                    if(grid[i][j]==0)
                    {
                         dfs(i, j, grid, visited, m, n);
                    }
                       
                }
            }
        }
        int cnt = 0;
        for(int i = 0 ;i <m ;i++)
        {
            for(int j = 0; j< n;j++)
            {
                if(grid[i][j] == 0)
                {
                       dfs(i,j, grid, visited,m,n);
                        cnt++;
                }
                
            }
        }
        return cnt;
    }
};