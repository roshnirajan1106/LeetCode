class Solution {
public:
    void set(int i,int j,vector<vector<int>>& matrix)
    {
        for(int k = 0 ;k<matrix.size();k++)
        {
           
            matrix[k][j] = 0;
        }
        for(int k = 0 ;k<matrix[0].size();k++)
        {
           
            matrix[i][k] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>>res;
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == 0)
                {
                    res.push_back({i,j});
                }
            }
        }
       for(int i = 0;i<res.size();i++)
       {
           
               set(res[i][0],res[i][1],matrix);
           
       }
        
        
    }
};