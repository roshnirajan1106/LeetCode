class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       int ans = INT_MAX;
        int n = triangle.size();
        if(n == 1)
        {
            for(int i = 0;i<triangle[0].size();i++)
                ans = min(ans, triangle[0][i]);
            
            return ans;
        }
        for(int  i = 1;i<triangle.size();i++)
        {
            for(int j = 0; j<triangle[i].size();j++)
            {
                int op1 = INT_MAX, op2 = INT_MAX;
                //for every j compare it with two index j-1, j in i-1 
                if(j-1>=0)
                    op1 = triangle[i-1][j-1];
                if(j < triangle[i-1].size())
                    op2 = triangle[i-1][j];
                
                triangle[i][j] = triangle[i][j] + min(op1,op2);
                if(i ==n-1 )
                    ans = min(ans, triangle[i][j]);
            }
        }
        return ans;
    }
};