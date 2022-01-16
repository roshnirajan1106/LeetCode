class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
       //FIRST - MAINTAIN AN ARRAY 
        // THEN CHECK THE UPPER BOUND OF THAT ARRAY , IF UPPER BOUND = END THEN JUST PUSH IT
        //IF NOT , THE JUST REPLACE IT WITH 
        vector<int> res;
        for(auto p : a )
        {
            auto it = lower_bound(res.begin(), res.end(), p);
            if(it == res.end())
                res.push_back(p);
            else
                *it = p;
        }
        return res.size();
    }
    
};