class Pair{
    public:
    int branchSum;
    int mainSum;
    Pair(){
        branchSum = 0;
        mainSum = 0;
    }
};
class Solution {
public:
    
    Pair dfs(vector<vector<int>>&graph,int src,string &s)
    {
        Pair p;
        int branchSum = 1;
        int mainSum = 1;
        int maxBranchSum = 0;
        if(graph[src].size() == 0)
        {
            p.branchSum = 1;
            p.mainSum = 1;
            return p;
        }
        for(auto p : graph[src])
        {
            Pair p1 = dfs(graph,p,s);
            
            if(s[p] != s[src]){
                branchSum = max(branchSum,p1.branchSum + 1);
                
                mainSum = max(mainSum,max(p1.branchSum + maxBranchSum + 1 ,p1.mainSum));
            }else{
               // branchSum = max(branchSum,1);
                mainSum = max(mainSum,max(maxBranchSum + 1 ,p1.mainSum));
                
            }
            if(s[p] != s[src])
            maxBranchSum = max(p1.branchSum,maxBranchSum);
        }
        mainSum = max(mainSum ,branchSum);
        p.mainSum= mainSum;
        p.branchSum = branchSum;
        maxBranchSum = 0;
        return  p;
            
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>>graph(n);
        int root  = -1;
        for(int i = 0;i<parent.size();i++)
        {
            if(parent[i] == -1)
            {
                root = i;
                continue;
            }
            int p = parent[i];
            int c = i;
            graph[p].push_back(c);
        }
        Pair p = dfs(graph,root,s);
        return p.mainSum;
        
    }
};