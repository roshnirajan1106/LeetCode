class Solution {
public:
    bool dfs(vector<int>&ans,  map<int, vector<int>> &graphs,vector<int> &visited, vector<int> stack , int src )
    {
        visited[src] =1;
        stack[src]  =1;
        for(auto p : graphs[src])
        {
            if(stack[p] == 1)
                return false;
            if(visited[p] == 0)
            {
                bool flag  = dfs(ans, graphs, visited, stack, p);
                if(flag == false)
                    return false;
            }
        }
        ans.push_back(src);
        stack[src] = 0;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> visited(numCourses,0);
        vector<int> stack(numCourses,0);
        map<int, vector<int>> graphs;
        vector<int> v;
        for(int i = 0;i<prerequisites.size();i++)
        {
            int x = prerequisites[i][0];
            int y =prerequisites[i][1];
            
            graphs[x].push_back(y);
        
        }
        
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i] == 0)
            {
              bool flag=   dfs(ans, graphs, visited, stack, i);
                if(flag == false)
                {
                    
                    return v;
                }
                
            }
        }
        
        return ans;
        
    }
};