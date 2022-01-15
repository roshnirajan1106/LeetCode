// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
bool dfs(int src, vector<int>adj[], int V, vector<int>&visited, int c)
{
    visited[src] = c;
    for(auto p : adj[src])
    {
        if(visited[p] == 0)
        {
            bool ans= dfs(p, adj,V, visited, 3-c);
            if(ans == false)
            return false;
        }
        if(visited[p] == visited[src] || p == src)
        return false;
    }
    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	  
	   vector<int> visited(V,0);

	   int src =0;
	   for(int i = 0;i <V;i++)
	   {   
	      if(adj[i].size() !=0 && visited[i] == 0)
	        {
	           bool ans =  dfs(i, adj,V, visited,1);
	           if(ans == false)
	           return false;
	       
	        }
	   }

	  
	  return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends