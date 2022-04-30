class Solution {
public:
    bool bipar(int color,int src, vector<vector<int>>& graph,vector<int>&visited)
    {
        visited[src]= color;
        for(auto p :graph[src])
        {
            if(visited[p] == -1)
            {
                bool ans = bipar(3-color,p,graph,visited);
                if(ans == false)
                    return false;

            }
            else if(visited[p] == visited[src])
            {
                return false;
            }
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n,-1);
        bool ans = true;
         for(int i = 0;i<n;i++)
        {
            if(visited[i] == -1)
            {
                ans = bipar(1,i,graph,visited);
                if(ans == false)
                    return false;
            }
        }
        return true;
    }
};