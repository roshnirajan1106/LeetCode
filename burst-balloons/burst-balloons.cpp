class Solution {
public:
    int solve(int s , int e , vector<vector<int>> &dp ,vector<int> &nums)
    {
        if(s > e)
            return 0;
        if(s == e)
        {   int temp= nums[s];
            if(s-1 > 0)
                temp *= nums[s-1];
            if(e+1 < nums.size())
                temp*= nums[e+1];
         
         return temp;
                
        }
        if(dp[s][e] != -1)
            return dp[s][e];
        
        int max_len = INT_MIN;
        for(int k = s ; k <=e; k++)
        {
            int temp = nums[k];
            temp *= nums[s-1];
            temp*=nums[e+1];
            
            temp += (solve(s,k-1,dp,nums) + solve(k+1,e,dp,nums));
            max_len = max(max_len,temp);
        
        }
        dp[s][e] = max_len;
        return dp[s][e];

    }
    int maxCoins(vector<int>& nums) {
        vector<int> new_num;
        new_num.push_back(1);
        for(int i = 0;i<nums.size();i++)
        {
            new_num.push_back(nums[i]);
        }
        new_num.push_back(1);
        int n = new_num.size();
        vector<vector<int>> dp(n , vector<int>(n,-1));
        
       return solve(1,n-2, dp,new_num);
        
        
    }
};