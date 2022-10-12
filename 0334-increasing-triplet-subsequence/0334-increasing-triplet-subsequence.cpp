class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>res;
        for(int i = 0;i<nums.size();i++)
        {
            auto it = lower_bound(res.begin(),res.end(),nums[i]);
            if(it == res.end())
                res.push_back(nums[i]);
            else
                *it= nums[i];
            
            if(res.size() > 2)
                return true;
        }
        return false;
    }
};