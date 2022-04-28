class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        set<pair<int,pair<int,int>>>s;
        int m = heights.size();
        int n = heights[0].size();
        s.insert({0,{0,0}});
        vector<vector<int>>res(m,vector<int>(n,INT_MAX));
        vector<int>xx = {-1,0,1,0};
        vector<int>yy = {0,1,0,-1};
        while(!s.empty())
        {
            auto top = *s.begin();
            s.erase(s.begin());
            int val = top.first;
            int x = top.second.first;
            int y = top.second.second;
            res[x][y] = val;
            if(x == m-1 && y == n-1 )
                return val;
            
            for(int k =0;k <4;k++)
            {
                int i = x + xx[k];
                int j = y + yy[k];
                
                if(i > m-1  || j > n-1 || i < 0 || j < 0 )
                    continue;
                int result = abs(heights[i][j] - heights[x][y]) ;
                result = max(result,val);
                
                if(result < res[i][j])
                    s.insert({result,{i,j}});
                
                
                
            }
        }
        return 0;
    }
};