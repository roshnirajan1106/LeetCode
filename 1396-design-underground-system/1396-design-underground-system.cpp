class UndergroundSystem {
public:
    map<int,pair<string,int>>m;
    map<string,vector<pair<string,int>>>cal;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        m[id] = make_pair(stationName,t); 
    }
    
    void checkOut(int id, string stationName, int t) {
        int time = t - m[id].second;
        string start = m[id].first;
        cal[start].push_back({stationName,time});
    }
    
    double getAverageTime(string startStation, string endStation) {
        double time = 0.0;
        double cnt = 0;
        for(auto p: cal[startStation])
        {
            if(p.first == endStation )
            {
                time += p.second;
                cnt++;
            }
                
        }
        return time/cnt;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */