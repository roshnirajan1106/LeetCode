class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>csum;
        int sum = 0;
        int ans = 0;
        for(int i =0;i<nums.size();i++)
        {
            sum +=nums[i];
            if(csum.find(sum-k) != csum.end() )
            {
                ans += csum[sum-k];
            }
            if(sum == k)
                ans +=1;
            if(csum.find(sum) == csum.end())
            {
                csum[sum] = 1;
            }
            else if(csum.find(sum) !=csum.end())
                csum[sum]++;
        }
        return ans;
    }
};