// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n  =grid[0].size();
        
        set<pair<int,pair<int,int>>>s;
        s.insert({grid[0][0],{0,0}});
        vector<int>xx = {0,-1,0,1};
        vector<int>yy= {1,0,-1,0};
        vector<vector<int>>dis(m,vector<int>(n,INT_MAX));
        dis[0][0] = grid[0][0];
        while(!s.empty())
        {
            auto top = *s.begin();
            s.erase(s.begin());
            int sum= top.first;
            int i = top.second.first;
            int j = top.second.second;
            if(i == m-1 && j == n-1)
            return sum;
            for(int k = 0;k<4;k++)
            {
                int x = i+xx[k];
                int y = j+yy[k];
                if(x<0 || y<0 || x>m-1 || y>n-1 || dis[x][y] < sum + grid[x][y])
                continue;
                
                
                dis[x][y] = sum + grid[x][y];
                s.insert({dis[x][y],{x,y}});
            }
        }
        return -1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends