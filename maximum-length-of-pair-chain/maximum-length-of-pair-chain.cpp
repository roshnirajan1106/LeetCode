class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n =pairs.size();
        vector<int>res;
        for(auto p :pairs)
        {
            auto it = lower_bound(res.begin(),res.end(),p[0]);
            if(it == res.end())
                res.push_back(p[1]);
            else if(*it > p[1])
                *it = p[1];
            }
        
    
          return res.size(); 
        
    }
};