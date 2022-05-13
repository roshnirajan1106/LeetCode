class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>m;
        for(int i = 1 ;i<nums.size();i++)
        {
            nums[i] += nums[i-1];
        }
        int ans=0;
        for(auto p : nums)
        {
            int rem = ((p%k) + k) %k;
            m[rem]++;
        }
        for(auto p : m)
        {
            int freq = p.second;
            ans += (freq*(freq-1))/2;
        }
        return ans + m[0];
    }
    
};