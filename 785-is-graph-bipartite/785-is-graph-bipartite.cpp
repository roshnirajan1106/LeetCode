class Solution {
public:
     bool dfs(vector<vector<int>>&graph , int src, vector<int>&visited,int c)
    {
        visited[src] = c;
        for(auto p :graph[src])
        {
            if(visited[p] == 0)
            {
                bool ans = dfs(graph,p, visited, 3-c);
                if(!ans)
                    return false;
                
                    
            }
            if(visited[p] == visited[src])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
         
       int n= graph.size();
        vector<int>visited(n,0);
        bool ans;
        for(int i = 0;i<n;i++)
        {
            if(visited[i] == 0)
            {
                ans = dfs(graph,i,visited,1);
                if(ans == false)
                    return false;
            }
        }
        return true;
    }
};