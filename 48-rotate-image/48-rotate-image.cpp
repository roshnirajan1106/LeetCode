class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(),matrix.end());
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = i+1;j<matrix[0].size();j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
// 7 8 9
// 4 5 6
// 1 2 3
// 0,1 1,0
// 0,2 2,0