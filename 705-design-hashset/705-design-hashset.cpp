class MyHashSet {
public:
    vector<int>v;
    MyHashSet() {
        v.resize(1000001);
    }
    
    void add(int key) {
       v[key] ++;
    }
    
    void remove(int key) {
       v[key] = 0;
    }
    
    bool contains(int key) {
        if(v[key] == 0)
            return false;
        
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */