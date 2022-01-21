class Solution {
public:
    int find_the_distinct_permutations(vector<int>&dp, vector<int>&nums,int sum, int target)
    {
        if(sum == target)
            return 1;
        if(sum  > target)
            return 0;
        if(dp[sum]!= -1 )
            return dp[sum];
        int count = 0;
        for(int i = 0; i<nums.size();i++)
        {   if(sum + nums[i] <=target)
                count += find_the_distinct_permutations(dp,nums,sum+nums[i],target);
        }
        dp[sum] = count;
        return dp[sum];
        
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target + 1,-1);
       return  find_the_distinct_permutations(dp, nums, 0,target);
    }
};