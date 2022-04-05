class Solution {
public:
    vector<int> dfs(int src,map<int,vector<int>>&graph,vector<int>&visited,vector<int>&stack,vector<int>&ans)
    {
        stack[src] = 1;
        visited[src]  =1;
        for(auto p: graph[src])
        {
            if(stack[p] == 1)
            {
                vector<int>v;
                return v;
            }
            if(visited[p] == 1)
                continue;
            vector<int>v  = dfs(p,graph,visited,stack,ans);
            if(v.size() == 0)
                return v;
            
        }
        ans.push_back(src);
        return ans;
        
    }
    vector<int> bfs(map<int,vector<int>>&graph,vector<int>&indegree,int num)
    {
        queue<int>q;
        for(int i = 0;i<num;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            auto top =q.front();
            q.pop();
            ans.push_back(top);
            
            for(auto p : graph[top])
            {
                if(--indegree[p] == 0 )
                    q.push(p);
            }
            
        }
        return ans;
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>>graph;
        vector<int>indegree(numCourses,0);
        for(auto p :prerequisites)
        {
            int src= p[0];
            int dest = p[1];
            indegree[src]++;
            graph[dest].push_back(src);
        }
        vector<int>v;
        vector<int>visited(numCourses,0);
        vector<int>stack(numCourses,0);
        
        vector<int>ans1 = bfs(graph,indegree,numCourses);
        if(ans1.size() == numCourses)
            return ans1;
        return v;
    }
};