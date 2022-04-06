// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool find(int i, int j, int m, int n, vector<vector<int>>& grid,vector<vector<int>>& visited)
    {
        if(i > m - 1 || j > n -1 || i < 0 || j < 0 || visited[i][j] == 1 || grid[i][j] == 0 )
        return false;
        if(grid[i][j] == 2)
        {
            return true;
        }
        visited[i][j]  =1 ;
        int ans =  find(i+1,j,m,n,grid,visited) || find(i-1,j,m,n,grid,visited) || find(i,j+1,m,n,grid,visited) ||find(i,j-1,m,n,grid,visited) ;
        visited[i][j] = 0;
        return ans;
        
        
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int m = grid.size();
        int n= grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int x = 0;
        int y = 0;
        int flag =0;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    x = i;
                    y =j;
                    flag = 1;
                    break;
                }
                if(flag)
                break;
            }
        }
        return find(x,y,m,n,grid,visited);
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
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends