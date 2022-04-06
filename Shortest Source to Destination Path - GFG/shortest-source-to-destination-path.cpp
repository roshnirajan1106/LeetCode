// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        set<pair<int,pair<int,int>>>s;
        int m = A.size();
        int n =A[0].size();
        vector<vector<int>>dis(m,vector<int>(n,INT_MAX));
        vector<int>xx ={-1,0,1,0};
        vector<int>yy= {0,1,0,-1};
        dis[0][0] = 0;
        if(A[0][0] == 0)
        return -1;
        s.insert({dis[0][0],{0,0}});
        while(!s.empty())
        {
            auto top = *s.begin();
            s.erase(s.begin());
        
            int wt = top.first;
            int x = top.second.first;
            int y = top.second.second;
            //cout<<x<<" "<<y<<endl;
            if(x == X && y == Y)
                return wt;
            for(int k = 0;k<4;k++)
            {
                int i = x + xx[k];
                int j = y + yy[k];
            
                if(i > m-1 || j > n-1 || i < 0 || j < 0 || A[i][j] == 0 || dis[i][j] < wt + 1)
                    continue;
                    dis[i][j] = wt +1;
                    // cout<<x<<" "<<y<<endl;
                    // cout<<dis[i][j]<<endl;
                    
                    s.insert({dis[i][j],{i,j}});
            }
        }
        return -1;
        
        
    }   
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends