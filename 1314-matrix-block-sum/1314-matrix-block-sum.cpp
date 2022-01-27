class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> output(m , vector<int>(n,0));
        
        vector<vector<int>>dp(m+1, vector<int>(n+1,0));
        
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
      
        for(int i = 0; i< m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                int x = i+1;
                int y = j+1;
                //(x +k , y+k) (x +k, y-k),(x-k)(y-k) , (x-k)(y+k)
                int sum1 = dp[min(x+k,m)][max(0,y-k-1)];
                int sum2 = dp[max(x-k-1,0)][max(y-k-1,0)];
                int sum3 = dp[max(x-k-1,0)][min(y+k,n)];
                int sum4 = dp[min(x+k,m)][min(y+k, n)];
                
                output[i][j] = sum4 +sum2-sum1-sum3;
                
            }
        }
        return output;
    }
};