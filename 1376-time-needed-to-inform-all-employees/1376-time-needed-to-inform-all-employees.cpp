class Solution {
public:
    int dfs(int src, vector<int> &visited,vector<int>& informTime,  map<int,list<int>> &graph)
    {
    
        int time = 0;
        for(auto p : graph[src])
        {
            time = max(time,  dfs(p, visited, informTime, graph));
        }
        return time + informTime[src];
        
        
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int,list<int>> graph;
        vector<int> visited(n,0);
        for(int i = 0;i<n;i++)
        {
            if(manager[i] == -1)
                continue;
            else{
                graph[manager[i]].push_back(i);
            }
        }
        int src= headID;
        
        return dfs(src, visited, informTime, graph);
        
    }
};