class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n =obstacleGrid[0] .size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        
       vector< vector<int>> res(m, vector<int> (n,0));
        res[0][0] = 1;
        for(int i =1;i<m ;i++)
        {
            if(obstacleGrid[i][0] == 1)
            {
                res[i][0] = 0;
                break;
            }
            else
                res[i][0] =1;
        }
        for(int j =1;j<n;j++)
        {
            if(obstacleGrid[0][j] == 1)
            {
                   res[0][j] = 0;
                    break;
            }
             
            else
                res[0][j] =1;
        }
        for(int i =1;i<m;i++)
        {
            for(int j =1;j<n;j++)
            {
                if(  obstacleGrid[i][j] ==1)
                    res[i][j] =0;
                else
                {
                    res[i][j] = res[i-1][j] + res[i][j-1];
                }
            }
        }
        return res[m-1][n-1];
        
    }
};