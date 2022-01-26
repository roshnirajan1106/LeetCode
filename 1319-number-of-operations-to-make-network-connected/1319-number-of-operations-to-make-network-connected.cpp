class Solution {
public:
    void dfs(map<int,vector<int>>&graph, int src, vector<int>&visited)
    {
        visited[src] =1;
        for(auto p: graph[src])
        {   if(visited[p] == 0)
                dfs(graph, p, visited);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> visited(n,0);
        if(n-1 > connections.size())
            return -1;
        map<int,vector<int>> graph;
        for(auto p : connections)
        {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }
        int cnt =0 ;
        for(int i = 0;i<visited.size();i++)
        {
            if(visited[i] == 0)
            {
                dfs(graph,i, visited);
                cnt++;
            }
        }
        return cnt-1;
    }
};