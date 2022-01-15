class Solution {
public:
    bool dfs( map<int, vector<int>> &graph , int src, vector<int>&visited,int c)
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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        map<int, vector<int>> graph;
        for(int i = 0 ;i <dislikes.size();i++)
        {
               int x = dislikes[i][0];
                int y = dislikes[i][1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        vector<int>visited(n+1,0);
        bool ans;
        for(int i = 1;i<=n;i++)
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