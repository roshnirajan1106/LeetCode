class Solution {
public:
    int find(int i,vector<int>&parent)
    {
        if(parent[i] == -1)
            return i;
        return parent[i] = find(parent[i],parent);
    }
    void unionset(int i , int j, vector<int>&parent,vector<int>&rank)
    {
        int s1 = find(i,parent);
        int s2 = find(j,parent);
        if(rank[s1] > rank[s2])
        {
            parent[s2] = s1;
            rank[s1] += rank[s2];
        }
        else{
            parent[s1] = s2;
            rank[s1] += rank[s2];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n+1,-1);
        vector<int>res;
        vector<int>rank(n+1,1);
        for(auto p : edges)
        {
            int i = p[0];
            int j = p[1];
            int s1 = find(i,parent);
            int s2 = find(j,parent);
            if(s1 == s2)
            {
                res.push_back(i);
                res.push_back(j);
                break;
            }
            unionset(i,j,parent,rank);
        }
    return res;
}
    
};