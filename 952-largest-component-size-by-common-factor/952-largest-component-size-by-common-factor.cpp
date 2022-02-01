class Solution {
public:
    int find(int x, vector<int>&parent)
    {
        if(parent[x] == -1)
            return x;
        return parent[x] = find(parent[x],parent);
    }
    void unionset(int x, int y, vector<int>&parent,vector<int>&rank)
    {
        int s1 = find(x,parent);
        int s2 = find(y,parent);
        if(s1 !=s2)
        {
            if(rank[s2] < rank[s1])
            {
                rank[s1] += rank[s2];
                parent[s2] = s1;
            }
            else{
                rank[s2] += rank[s1];
                parent[s1] = s2;
            }
        }
    }
    int largestComponentSize(vector<int>& nums) {
        vector<int>parent(100001,-1);
        vector<int> rank(100001,-1);
        for(auto p : nums)
        {
            for(int k  =2;k<=sqrt(p) ;k++)
            {
                if(p % k==0)
                {
                    unionset(k,p,parent,rank);
                    unionset(p/k,p,parent,rank);
                }
            }
        }
        map<int,int> m;
        int ans = 0;
        for(auto p:nums)
        {
            int s1 = find(p,parent);
            m[s1] ++;
            ans = max(ans,m[s1]);
        }
        return ans;
        
    }
};