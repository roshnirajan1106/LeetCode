class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //map<int,int>times;
        vector<int>visited;
        map<int,int>dist;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,k});
        map<int,vector<pair<int,int>>>graph;
        for(int i = 0;i<times.size();i++)
        {
            int src = times[i][0];
            int dest = times[i][1];
            int d = times[i][2];
            graph[src].push_back({dest,d});
            
        }
        for(int i =1;i<=n;i++)
        {
            dist[i] = INT_MAX;
        }
        dist[k] = 0;
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int distance = top.first;
            int node = top.second;
            for(auto p : graph[node])
            {
                int neigh=p.first;
                int diff = p.second;
                if(distance +  diff < dist[neigh])
                {
                    dist[neigh] = distance + diff;
                    pq.push({dist[neigh],neigh});
                }
                else
                    continue;
            }
        }
        int ans = INT_MIN;
        for(auto p : dist)
        {
            if(p.second == INT_MAX)
                return -1;
            
            ans = max(ans,p.second);
        }
        
        return ans;
    }
};