class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        if(grid[0][0] == 1)
            return -1;
        int m = grid.size();
        int n = grid[0].size();
    vector<vector<int>>visited(m,vector<int>(n,0));

        q.push({0,0});
        
        visited[0][0] = 1;
        
        int len = 1;
        vector<pair<int,int>>arr;
        arr.push_back({0,1});
        arr.push_back({0,-1});
        arr.push_back({1,0});
        arr.push_back({-1,0});
        arr.push_back({-1,-1});
        arr.push_back({1,1});
        arr.push_back({-1,1});
        arr.push_back({1,-1});
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto top = q.front();
                q.pop();
                int x = top.first;
                int y = top.second;
                //visited[x][y] = 1;
                if(x == m-1 && y == n-1)
                    return len;
                
                
                for(auto p : arr)
                {
                    int xx = p.first + x;
                    int yy = p.second + y;
                    if(xx <0 || yy<0 ||xx >m-1 ||yy>n-1 || visited[xx][yy] ==1 || grid[xx][yy] == 1)
                        continue;
                    visited[xx][yy] = 1;
                    q.push({xx,yy});
                    
                    
                }
                
                
                
            }
            len ++;
            
        }
        return -1;
    }
};