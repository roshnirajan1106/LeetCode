class Solution {
public:
    void dfs(int src, vector<vector<int>>  &rooms, vector<int> &visited)
    {
        visited[src] = 1;
        for(auto p : rooms[src])
        {
            if(visited[p] == 0)
                dfs(p, rooms, visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n,0);
        dfs(0, rooms, visited);
        for(auto p  : visited)
        {
            if(p == 0)
                return false;
        }
        return true;
    }
};