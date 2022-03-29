class Solution {
public:
    int find(int i, vector<int>&parent)
    {
        if(parent[i] == -1)
            return i;
        return parent[i] = find(parent[i],parent);
    }
    void unionset(int i,int j, vector<int>&parent, vector<int>&rank)
    {
        int s1 = find(i,parent);
        int s2 = find(j,parent);
        if(s1 == s2)
            return ;
        
        
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
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
         int m = connections.size();
        if(n > m + 1)
            return -1;
        
        vector<int>parent(n,-1);
        vector<int>rank(n,1);
        for(int i = 0;i<m;i++)
        {
            int src = connections[i][0];
            int dest = connections[i][1];
            unionset(src,dest,parent,rank);
        }
        int count= 0;
        for(auto p : parent)
        {
            if(p == -1)
                count++;
        }
        
        return count-1;
    }
};