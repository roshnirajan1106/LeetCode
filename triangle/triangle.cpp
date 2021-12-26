class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int count = INT_MAX;
        if(n ==1)
            return triangle[0][0];
        for(int i =1;i<n;i++)
        {
            for(int j = 0;j < triangle[i].size();j++)
            {    int s = INT_MAX;
                if(j-1 >=0 )
                    s= min(triangle[i-1][j-1] ,s );
                if(j<triangle[i-1].size() )
                    s= min(s, triangle[i-1][j]);
             
                triangle[i][j] += s;
             
                if(i == n-1)
                    count = min(count, triangle[i][j]);
                    
            }
        }
        return count;
    }
};