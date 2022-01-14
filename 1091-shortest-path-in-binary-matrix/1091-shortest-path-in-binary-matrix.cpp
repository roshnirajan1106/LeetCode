class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        int dist = 0;
        queue<pair<int,int>> q;
        
        
        
       
        
        vector<vector<int>> v;
        v.push_back({0,1});
        v.push_back({0,-1});
        
        v.push_back({1,0});
        v.push_back({-1,0});
        v.push_back({1,1});
        v.push_back({1,-1});
        v.push_back({-1,1});
        v.push_back({-1,-1});
        
        
        grid[0][0]=1;
        q.push({0,0});
      
        while(!q.empty())
        {
            int size=  q.size();
          
            dist++;
            while(size--)
            {  
                pair<int,int> top = q.front();
                q.pop();
                int x = top.first;
                int y = top.second;
                cout<<x<<" "<<y<<endl;
                if(x == n-1 && y == n-1)
                    return dist;
                for(int i = 0 ;i<8;i++)
                {
                    int xx = x + v[i][0];
                    int yy = y + v[i][1];
                    if(xx > n-1 || xx < 0 || yy > n-1 || yy < 0 || grid[xx][yy] != 0)
                        continue;
                    else{
                        grid[xx][yy] = 1;
                        q.push({xx,yy});
                        
                    }
                    
                }
            }
            
        }
        return -1;
    }
};