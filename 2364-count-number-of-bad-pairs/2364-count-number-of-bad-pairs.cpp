class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,long long>dp;
        long long count  = 0;
        for(int i = 0;i<nums.size();i++)
        {
            int diff = nums[i] - i;
            if(dp.find(diff) == dp.end())
                dp[diff] = 1;
            else{
                count += dp[diff];
                dp[diff]++;
            }
        }
        long long n = nums.size()-1;
        long long sum = n * (n + 1 );
        sum = sum/2;
        return sum - count;
    }
};