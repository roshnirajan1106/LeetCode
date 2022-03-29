class Solution {
public:
    int find(int i, vector<int>&parent)
    {
        if(parent[i] == -1)
            return i;
        return parent[i] = find(parent[i],parent);
    }
    bool unionset(int i,int j, vector<int>&parent, vector<int>&rank)
    {
        int s1 = find(i,parent);
        int s2 = find(j,parent);
        if(s1 == s2)
            return true;
        
        
        if(rank[s1] > rank[s2])
        {
            parent[s2] = s1;
            rank[s1] += rank[s2];
        }
        else
        {
            parent[s1] = s2;
            rank[s2] += rank[s1];
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n,-1);
        vector<int>rank(n,-1);
        vector<int>ans;
        for(int i = 0;i<n ;i++){
           
                int src = edges[i][0]-1;
                int dest = edges[i][1]-1;
                bool res =unionset(src,dest,parent,rank);
                if(res == true){
                    ans.push_back(src+1);
                    ans.push_back(dest+1);
                    return ans;
                }
            
        }
        return ans;
        
    }
};