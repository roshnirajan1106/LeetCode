class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> count;
        int n = nums.size();
        n = n /2;
        for(auto p: nums)
            count[p] ++;
        for(auto p : count)
        {
            if(p.second  > n)
                return p.first;
            

        }
        return -1;
    }
};