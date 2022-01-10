class Solution {
public:
    int find(int x,vector<int> &parent)
    {
        if(parent[x] == -1)
            return x;
        return parent[x] = find(parent[x],parent);
    }
    void unions(int x, int y, vector<int> &parent)
    {
        int s1 = find(x, parent);
        int s2 = find(y, parent);
        if(s1 != s2)
        {
            parent[s2] = s1;
            
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n  =stones.size();
        vector<int> parent(n,-1);
        for(int i = 0; i< n-1;i++)
        {
            for(int j = 1;j<n;j++)
            {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    unions(i,j,parent);
                
            }
        }
        int count = 0;
        for(int i = 0; i< n;i++)
        {
            if(parent[i] == -1)
                count++;
        }
        return n - count;
    }
};