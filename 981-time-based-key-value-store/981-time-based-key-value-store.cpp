class TimeMap {
public:
    map<int, map<string, string>>m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map<string,string>temp = m[timestamp];
        temp[key] = value;
        m[timestamp] = temp;
    }
    
    string get(string key, int timestamp) {
        for(int i = timestamp;i>=0;i--)
        {
            map<string,string>temp = m[i];
            if(temp.find(key) == temp.end())
                continue;
            else
                return temp[key];
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */