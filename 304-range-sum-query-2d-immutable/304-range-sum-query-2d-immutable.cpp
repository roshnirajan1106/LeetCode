class NumMatrix {
public:
   
    vector<vector<int> > dp;
    NumMatrix(vector<vector<int>>& mat) {
        
        
        int m = mat.size();
        int n = mat[0].size();
         dp.resize(m+1, vector<int>(n+1,0));    
       
        for(int i = 0; i< m ;i++)
        {
            for(int j = 1;j<n;j++)
            {
                mat[i][j] += mat[i][j-1];
            }
        }
        for(int j = 0;j<n;j++)
        {
            for(int i = 1;i<m;i++)
            {
                mat[i][j] += mat[i-1][j];
            }
        }
        for(int i = 0;i<m;i++)
        {
            for(int j = 0; j<n;j++)
            {
                dp[i+1][j+1] = mat[i][j];
                
            }
        }
        
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1 = row1+1;
        col1 = col1+1;
        row2 = row2+1;
        col2 = col2+1;
        return dp[row2][col2] - dp[row1-1][col2] - dp[row2][col1 -1 ] + dp[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */