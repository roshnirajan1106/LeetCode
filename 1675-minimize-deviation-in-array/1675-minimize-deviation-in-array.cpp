class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
       multiset<int>s;
        for(auto p : nums)
        {
            if(p % 2 == 0)
                s.insert(p);
            else
                s.insert(p*2);
        }
        auto it = s.end();
        it--;
        int ans = INT_MAX;
        ans = min(ans,*it - *s.begin());
        while(*it % 2 == 0  )
        {
            s.insert((*it) / 2);
            s.erase(it);
            it = s.end();
            it--;
            
            ans = min(ans, *it- *s.begin());
            
        }
        return ans;
    
        
        
    }
};