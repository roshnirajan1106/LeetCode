class FreqStack {
public:
    priority_queue<pair<int,pair<int,int>>>pq;
    map<int,int>freq;
    int time ;
    FreqStack() {
        time = 0;
    }
    
    void push(int val) {
        pq.push(make_pair(++freq[val],make_pair(++time,val)));
    }
    
    int pop() {
        auto p = pq.top();
        int x = p.second.second;
        pq.pop();
        freq[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */