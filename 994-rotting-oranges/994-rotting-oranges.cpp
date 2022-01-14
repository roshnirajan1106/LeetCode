class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
       
        int n = grid[0].size();
        int count = 0;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
                if(grid[i][j]==0)
                    count++;
            }
        }
    
        if(q.size() == 0)
          { 
            if(count == m*n)
                return 0;
            return -1;
        }
        vector<vector<int>> v;
        v.push_back({-1,0});
        v.push_back({1,0});
        v.push_back({0,-1});
        v.push_back({0,1});
        int dist = 0;
        while(!q.empty())
        {   
            int size = q.size();
            dist ++;
            while(size--)
            {   
                pair<int,int> top = q.front();
                q.pop();
                int x = top.first;
                int y = top.second;
                for(int i = 0;i<4;i++)
                {
                    int xx = x + v[i][0];
                    int yy =y + v[i][1];
                    if(xx > m-1 || xx <0 || yy> n-1 ||yy<0 ||grid[xx][yy] != 1) continue;
                    
                    grid[xx][yy] = 2;
                    q.push({xx,yy});
                }
            }
                
        }
        for(auto p : grid)
            for(auto q:p)
                if(q == 1)
                    return -1;
        
        
        return dist-1;
       
    }
    
};