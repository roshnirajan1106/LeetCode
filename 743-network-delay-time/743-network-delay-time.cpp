class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //src = 0;
        //all the nodes excpet src = infinut
        set<pair<int,int>>s;
        vector<int>dist(n+1,INT_MAX);
        map<int,vector<pair<int,int>>>graph;
        for(auto p :times)
        {
            int src = p[0];
            int dest =p[1];
            int wt= p[2];
            graph[src].push_back({dest,wt});
        }
       
        dist[k] = 0;
        s.insert({0,k});
        while(!s.empty())
        {
            auto top = *s.begin();
            s.erase(s.begin());
            int node = top.second;
            int dis = top.first;
            
            for(auto p : graph[node]){
                int nbr = p.first;
                int wt = p.second;
                if(dis + wt < dist[nbr])
                {
                    if(s.find(make_pair(dist[nbr],nbr)) != s.end())
                        s.erase(s.find(make_pair(dist[nbr],nbr)));
                    
                    dist[nbr] = dis + wt;
                    s.insert({dist[nbr],nbr});
                }
                
            }
            
            
        }
        int maximum = INT_MIN;
        for(int i = 1;i<=n;i++)
        {
            if(dist[i] == INT_MAX)
                return -1;
            
            maximum = max(maximum,dist[i]);
                
        }
        return maximum;
    }
};