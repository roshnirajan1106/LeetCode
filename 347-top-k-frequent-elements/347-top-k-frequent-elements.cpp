class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        map<int,int>m;
        for(auto p : nums)
        {
            m[p] ++;
        }
        for(auto p :m)
        {
            pq.push({p.second,p.first});
        }
        vector<int>res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};