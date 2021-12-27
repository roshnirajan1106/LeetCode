class Solution {
public:
    
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
          
        vector<vector<int>>arr (m+1,vector<int> (n+1,0));
        int ans = 0;
        for(int i=1;i<=m ;i++)
        {
            for(int j = 1 ;j<=n;j++)
            {
                if(matrix[i-1][j-1] == '1')
                {
                    arr[i][j] = min(arr[i-1][j], min(arr[i][j-1], arr[i-1][j-1])) + 1;
                    cout<<arr[i][j]<<" ";
                    ans = max(ans, arr[i][j]);
                }
                cout<<endl;
                    
            }
        }
        return ans*ans;
        
    }                                                                        
};