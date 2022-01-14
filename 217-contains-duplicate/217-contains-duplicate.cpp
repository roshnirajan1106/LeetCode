class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m;
        for(auto p : nums)
        {
            m[p] ++;
            if(m[p] > 1)
                return true;
        }
        return false;
    }
};