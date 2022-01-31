class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        set<pair<int,int>>pq;
        vector<int> time(n+1,INT_MAX);
        time[k] = 0;
        map<int,vector<pair<int,int>>>graph;
        for(auto p : times)
        {
            graph[p[0]].push_back({p[1], p[2]});
        }
        pq.insert({0,k});
        while(!pq.empty())
        {
            pair<int,int> top = *(pq.begin());
            pq.erase(pq.begin());
            int src= top.second;
            int d =top.first;
            
            for(auto p : graph[src])
            {
                int nbr=p.first;
                int dist = p.second;
                if(dist + d < time[nbr])
                {
                    if(pq.find({time[nbr], nbr}) != pq.end())
                    {
                        pq.erase(pq.find({time[nbr], nbr}));
                    }
                    time[nbr]=  dist +d;
                    pq.insert({time[nbr],nbr});
                }
            }
        }
        int ans = 0;
        for(int i = 1;i<=n;i++)
        {
            if(time[i] == INT_MAX)
                return -1;
            ans = max(ans, time[i]);
        }
        return ans;
    }
};