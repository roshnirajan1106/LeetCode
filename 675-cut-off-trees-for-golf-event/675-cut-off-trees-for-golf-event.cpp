class Solution {
public:
    int minSteps(int i,int j, int x, int y,vector<vector<int>>& forest,int m, int n )
    {
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        vector<int>x_c= {-1,0,1,0};
        vector<int>y_c ={0,1,0,-1};
        queue<pair<int,int>>q;
        q.push({i,j});
        int step = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size-- )
            {
                 auto top = q.front();
            q.pop();
            
            int xx = top.first;
            int yy = top.second;
            if(xx == x && yy == y)
                return step;
            
            for(int k = 0;k<4;k++)
            {
                i = xx + x_c[k];
                j = yy + y_c[k];
                if(i > m-1 || j >n-1 ||i <0 ||j<0 ||visited[i][j] || forest[i][j] == 0)
                    continue;
                
                q.push({i,j});
                visited[i][j] = 1;
                
                
            }
            }
           
            
            
            step++;
        }
        
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>> > pq;
        int m = forest.size();
        int n = forest[0].size();
        for(int i = 0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(forest[i][j] != 0 && forest[i][j] != 1)
                    pq.push({forest[i][j],{i,j}});
            }
        }
        int steps= 0;
        int i = 0,j=0;
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int val = top.first;
            int x = top.second.first;
            int y = top.second.second;
            int step = minSteps( i,j,x, y,forest,m,n);
            
            if(step < 0)
                return -1;
            steps += step;
            i= x,j =y;
            forest[i][j] = 1;
        }
        
        
        return steps;
    }
};