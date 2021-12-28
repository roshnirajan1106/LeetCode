class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> num;
        int count = 0;
        int total_sum =0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] != 0)
            {
                num.push_back(nums[i]);
                total_sum += nums[i];
            }
            else{
                count++;
            }
        }
        int sum = (target+total_sum);
        if(sum <0)
            return 0;
        if(sum % 2 !=0)
            return 0;
        
        sum = sum /2;
        //sum =  4 -> 4-1 , 4+1 = 5;
        // totalsum = 10 , target = 4 => 7-3 is an option
        //6-2 is an option but 6 + 2 is not 10 , but we need 10
        int n = num.size();
        int dp[n+1][sum+1];
        memset( dp, 0, sizeof(dp) );
        for(int i = 0 ;i<n+1;i++)
        {
            dp[i][0] = 1;
        }
        for(int i = 1;i<n+1;i++)
        {
            for(int j =1;j<sum+1;j++)
            {
                if( num[i-1] <= j)
                {
                    dp[i][j] += dp[i-1][j-num[i-1]];
                }
                    dp[i][j] += dp[i-1][j];
                
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[n][sum]*max(1,1<<count);
        
    }
};