class Solution {
public:
  
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n =mat[0].size();
        queue<pair<int,int>> q;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i,j});
                }
                else{
                    mat[i][j] = -1;
                }
            }
        }
        vector<vector<int>> v;
        v.push_back({-1,0});
        v.push_back({1,0});
        v.push_back({0,-1});
        v.push_back({0,1});
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i< 4;i++)
            {
                int x = r + v[i][0];
                int y = c + v[i][1];
                if(x < 0 || y< 0 || x > m-1 || y> n-1 || mat[x][y] != -1  ) 
                    continue;
                mat[x][y] = 1 + mat[r][c];
                q.push({x,y});
            }
        }
        return mat;
    }
};