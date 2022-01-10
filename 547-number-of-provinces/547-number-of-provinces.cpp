class Solution {
public:
    void dfs(map<int,vector<int>> &adjList, vector<int> &visited, int src)
    {
        visited[src] = 1;
        for(auto p : adjList[src])
        {
            if(visited[p] == 0)
            {
                dfs(adjList, visited,p);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //convert to adjancecy list
        map<int,vector<int>> adjList;
        int n = isConnected.size();
        for(int i = 0; i< n;i++)
        {
            for(int j = 0 ;j<n;j++)
            {
                if(isConnected[i][j] == 1 && i != j)
                    adjList[i].push_back(j);
            }
        }
        int cnt = 0;
        vector<int> visited(n,0);
        for(int i = 0;i<n;i++)
        {
            if(visited[i] == 0)
            {   cnt++;
                dfs(adjList, visited,i);
            }
        }
        return cnt;
    }
};