class Solution {
public:
    void dfs(int src,vector<vector<int>>& graph,vector<int>&path ,vector<vector<int>>&ans,int target)
    {
        path.push_back(src);
        if(target == src)
        {
            
            ans.push_back(path);
            path.pop_back();
            return ;
        }
        
        for(auto p : graph[src])
        {
            dfs(p,graph,path,ans,target);
        }
        path.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       vector<vector<int>>ans;
        vector<int>path;
        int target = graph.size()-1;
        dfs(0,graph,path,ans,target);
        return ans;
    }
};