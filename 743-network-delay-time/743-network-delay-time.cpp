class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        map<int,vector<pair<int,int>>> graph;
        for(auto p : times)
        {
            int x = p[0];
            int y = p[1];
            int z =p[2];
            graph[x].push_back({y,z});
            
        }
        set<pair<int,int>> s;
        s.insert({k,0});
        while(!s.empty())
        {
            pair<int,int> top = *(s.begin());
            s.erase(s.begin());
            int parent = top.first;
            int d = top.second;
            for(auto p : graph[parent])
            {
                int child = p.first;
                int wt  = p.second;
                cout<<child<<" "<<wt<<endl;
                if(wt + d < dist[child])
                {
              
                    if(s.find({child, dist[child]}) != s.end())
                        s.erase({child, dist[child]});
                    s.insert({child, wt+d});
                    dist[child] = wt+d;
                }
                
                
                
            }
        }
        int time = 0;
        for(int i = 1;i<=n;i++)
        {
            if( dist[i] == INT_MAX)
                return -1;
            time = max(time, dist[i]);
        }
        return time;
    }
};