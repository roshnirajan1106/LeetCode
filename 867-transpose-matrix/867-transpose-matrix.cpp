class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>res(n,vector<int>(m));
        int i = 0;
    
        while(i<m)
        {
            int j = 0;
            while(j<n)
            {
                res[j][i] =matrix[i][j];
                j++;
            }
            i++;
        }
        return res;
    }
};