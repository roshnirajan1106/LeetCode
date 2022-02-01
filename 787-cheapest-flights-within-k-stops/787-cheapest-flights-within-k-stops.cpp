class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>distance(n,INT_MAX);
        map<int,vector<pair<int,int>>>graph;
        for(int i = 0;i<flights.size();i++)
        {
            int s = flights[i][0];
            int e = flights[i][1];
            int price= flights[i][2];
           
            graph[s].push_back({e,price});
        }
      
        
        distance[src] = 0;
       
        set<pair<int,pair<int,int>>>pq;
        pq.insert({0,{src,k}});
        while(!pq.empty())
        {
            auto top = *(pq.begin());
            pq.erase(pq.begin());
            
            int src = top.second.first;
            int k_value = top.second.second;
            int d =top.first;
            
            if(src == dst)
                return d;
            
            if(k_value < 0)
                continue;
            
            for(auto p : graph[src])
            {
                int dest = p.first;
                int price =p.second;
               
                    // if(pq.find({distance[dest],dest}) != pq.end())
                    //     pq.erase(pq.find({distance[dest],dest}));
              distance[dest] = d + price;
              pq.insert({distance[dest], {dest,k_value-1}});
                
                
            }
            
           
            
        }
        
         return -1;
    }
};