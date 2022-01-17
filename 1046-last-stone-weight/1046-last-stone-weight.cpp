class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto p  :stones)
            pq.push(p);
        
        while(pq.size() > 1)
        {
            int y = pq.top();
            pq.pop();
            int x= pq.top();
            pq.pop();
            pq.push(y-x);
        }
        if(pq.size() == 1)
            return pq.top();
        return 0;
    }
};