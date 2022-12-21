class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        map<int,int>m;
        for(int i = 0;i<nums.size();i++)
        {
            m[nums[i]] = i;
        }
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(nums[n-2] * 2 <= nums[n-1])
            return m[nums[n-1]];
        
        return -1;
    }
};