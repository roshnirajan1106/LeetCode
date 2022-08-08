class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int>dp;
        dp[0] = 1;
        map<int,int>connect;
        int final_max = 0;
        int idx = 0;
        //3,4,8,16
        for(int i = 1;i<nums.size();i++)
        {
            
            int max = 0;
            
            for(int j = i-1;j>=0;j--)
            {
                if(nums[i] % nums[j] == 0)
                {
                    if(dp[j] > max)
                    {
                        
                        max = dp[j];
                        connect[i] = j;
                    }
                }
                dp[i] = 1 + max;
                
            }
            if(final_max < dp[i])
            {
                idx = i;
                final_max = dp[i];
            }
                
        }
        vector<int>res;
        while(dp[idx] > 1)
        {
         res.push_back(nums[idx]);
            idx =connect[idx];
        }
        cout<<nums[idx]<<endl;
        res.push_back(nums[idx]);
        reverse(res.begin(),res.end());
        return res;
        
    }
};