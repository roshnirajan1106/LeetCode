class Solution {
public:
    void dfs(int src, vector<int>&parent,vector<int>&disc,vector<int>&low,vector<int>&stack,vector<int>&visited,map<int,vector<int>>& connections,vector<vector<int>>&output)
    {   static int time = 0;
     
        visited[src] = 1;
        stack[src] = 1;
        low[src] = time;
        disc[src] = time;
        time++;
        for(auto p : connections[src])
        {   
            if(stack[p] == 1 && parent[src] != p)
            {
                low[src] = min(disc[p], low[src]);
            }
            else if(visited[p] == 0)
            {
                parent[p] =src;
                dfs(p,parent, disc,low,stack,visited,connections,output);
                low[src] = min(low[src], low[p]);
                 if(low[p] > disc[src])
                output.push_back({p,src});
            }
            
           
        }
        stack[src] = 0;
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
     
        vector<int>parent(n,-1);
        vector<int>disc(n,-1);
        vector<int>low(n,-1);
        map<int,vector<int>> graph;
        for(auto p : connections)
        {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }
        vector<int>stack(n,0);
        vector<int>visited(n,0);
        vector<vector<int>>output;
        dfs(0,parent,disc,low,stack,visited,graph,output);
       
    
        return output;
    }
};