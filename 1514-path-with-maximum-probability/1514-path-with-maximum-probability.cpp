class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
         vector< pair<int,double> > graph[n];
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        set<pair<double,int>,greater<pair<double,int>>> pq;
        pq.insert({1.0, start});
        cout<<1<<" "<<start<<endl;
        vector<double> success(n,0);
        success[start] = 1;
        while(!pq.empty())
        {
            auto top = *(pq.begin());
            pq.erase(pq.begin());
            double s = top.first;
            int src = top.second;
            for(auto p : graph[src])
            {
                int nbr = p.first;
                double ss = p.second;
                if(ss*s > success[nbr])
                {
                    if(pq.find({success[nbr],nbr}) != pq.end())
                        pq.erase({success[nbr],nbr});
                    
                    success[nbr] = ss*s;
                    pq.insert({success[nbr],nbr});
                    cout<<success[nbr]<<" "<<nbr<<endl;
                }
            }
        }
      return success[end];
        
    }
};