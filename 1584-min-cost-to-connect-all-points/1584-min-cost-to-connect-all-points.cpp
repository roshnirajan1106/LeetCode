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
        int s1=find(x, parent);
        int s2= find(y,parent);
        if(s1 != s2)
        {
            if(rank[s1] > rank[s2])
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
            else{
                parent[s1] =s2;
                rank[s2] += rank[s1];
            }
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>> > pq;
        
        for(int i = 0;i<points.size()-1;i++)
        {
            for(int j = i+1;j<points.size();j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[j][1] - points[i][1]);
                pq.push({dist,{i,j}});
            }
        }
        vector<int>parent(points.size() , -1);
        vector<int>rank(points.size(),1);
        int sum =0;
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int s = top.first;
            int x = top.second.first;
            int y = top.second.second;
            
            
            int s1 = find(x,parent);
            int s2 = find(y,parent);
            if(s1 != s2)
            {
                sum += s;
                unionset(x,y,parent,rank);
            }
            
            
        }
        return sum;
        
    }
};