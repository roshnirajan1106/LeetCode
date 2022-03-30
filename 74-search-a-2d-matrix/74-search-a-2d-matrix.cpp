class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n =matrix[0].size();
        int i= 0;
        int j = n-1;
        while(i <m  && j >=0)
        {
            if(matrix[i][j] == target)
                return true;
            
            if(matrix[i][j] > target)
            {
                j--;
            }
            else
                i++;
        }
        // while(i < m )
        // {
        //     if(matrix[i++][j+1] == target)
        //         return true;
        // }
        // while(j >= 0)
        // {
        //     if(matrix[i-1][j--] == target)
        //         return true;
        // }
        return false;
    }
};