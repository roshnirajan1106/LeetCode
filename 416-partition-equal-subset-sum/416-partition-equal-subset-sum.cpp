class Solution {
public:
    bool canPartition(vector<int>& nums) {
       
        int n = nums.size();
        
        int sum = 0;
        for(auto p : nums)
            sum +=p;
        
        if(sum & 1)
            return false;
        sum = sum/2;
        vector<bool>dp(sum+1,false);
        dp[0] = true;
        for(auto p : nums)
        {
            for(int j = sum ; j>= p;j--)
            {
                if(j==p || dp[j-p]) 
                {
                    dp[j] = true;
                    //cout<<j<<" Possible"<<endl;
                }
                
            }
        }
        return dp[sum];
    }
};