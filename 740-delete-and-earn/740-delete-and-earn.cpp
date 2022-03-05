class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(10001,0);
        map<int,int>m;
        for(auto p :nums)
            m[p]++;
        int ans = 0;
        for(int i = 1;i<10001;i++)
        {
            if(m.find(i) == m.end())
                dp[i] = dp[i-1];
            else
                dp[i] = max(m[i] * i + dp[max(0,i-2)],dp[i-1]);
            
            ans = max(ans,dp[i]);
        }
        
        
        return ans;
    }
};