class Solution {
public:
   bool find_cycle(int src, vector<int>&stack,map<int,vector<int>>&graph,vector<int>&visited)
   {
       stack[src] = 1;
       visited[src] = 1;
       for(auto p : graph[src])
       {
           if(stack[p] == 1)
               return true;
           if(visited[p] == 1)
               continue;
           bool ans = find_cycle(p,stack,graph,visited);
            if(ans == true)
                return true;
       }
       stack[src] = 0;
       return false;
   }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>>graph;
        for(auto p :prerequisites)
        {
            int src= p[0];
            int dest = p[1];
            if(src == dest)
                return false;
            
            graph[dest].push_back(src);
        }
        
        vector<int>visited(numCourses,0);
        vector<int>stack(numCourses,0);
        
        for(int i = 0;i<numCourses;i++)
        {
            if(visited[i] == 0){
                
            cout<<i<<"--> ";
            bool ans = find_cycle(i,stack,graph,visited);
                cout<<ans<<endl;
            if(ans == true)
                return false;
                }
        }
        return true;
    }
};