class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       set<pair<int,pair<int,int>>>pq;
        pq.insert({0,{0,0}});
        int m = heights.size();
        int n =heights[0].size();
        vector<vector<int>>dist(m, vector<int>(n,INT_MAX));
        //vector<vector<int>>max_value(m,vector<int>(n,INT_MIN));
        //max_value[0][0] = 0;
        dist[0][0] = 0;
        while(!pq.empty())
        {
            auto  top = *(pq.begin());
            pq.erase(pq.begin());
            int effort = top.first;
            int x = top.second.first;
            int y =top.second.second;
            
            if(x == m-1 && y == n-1)
                return effort;
             
            //go left
            if(x> 0)
            {
                int xx = x-1;
                int yy = y;
                int nd = max(abs(heights[x][y] - heights[xx][yy]),effort);
                if(dist[xx][yy] >nd){
                    dist[xx][yy] = nd;
                    pq.insert({dist[xx][yy],{xx,yy}});
                   // max_value[xx][yy] = max(max_value[xx][yy], max_)
                }
            }
             if(y> 0)
            {
                int xx = x;
                int yy = y-1;
                int nd = max(abs(heights[x][y] - heights[xx][yy]),effort);
                if(dist[xx][yy] >nd){
                    dist[xx][yy] = nd;
                    pq.insert({dist[xx][yy],{xx,yy}});
                   // max_value[xx][yy] = max(max_value[xx][yy], max_)
                }
            }
             if(x<m-1)
            {
                int xx = x+1;
                int yy = y;
                int nd = max(abs(heights[x][y] - heights[xx][yy]),effort);
                if(dist[xx][yy] >nd){
                    dist[xx][yy] = nd;
                    pq.insert({dist[xx][yy],{xx,yy}});
                   // max_value[xx][yy] = max(max_value[xx][yy], max_)
                }
            }
             if(y<n-1)
            {
                int xx = x;
                int yy = y+1;
                int nd = max(abs(heights[x][y] - heights[xx][yy]),effort);
                if(dist[xx][yy] >nd){
                    dist[xx][yy] = nd;
                    pq.insert({dist[xx][yy],{xx,yy}});
                   // max_value[xx][yy] = max(max_value[xx][yy], max_)
                }
            }
            
            
            
        }
        return 0;
    }
                            
            
     
    };

