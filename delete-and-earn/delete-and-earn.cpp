class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        if(nums.size() == 1)
            return nums[0];
        set<int>s (nums.begin(),nums.end());
        map<int,int> m;
        for(int i = 0 ;i<nums.size();i++)
        {
            if(m.find(nums[i]) == m.end())
                m[nums[i]] = 1;
            else{
                m[nums[i]] ++;
            }
        }
        int max_len = 1;
        int n = s.size();
        vector<int> dp(n+1,0);
        vector<int> s1(s.begin(),s.end());
        for(auto p :s1)
            cout<<p<<" ";
        dp[0] = 0;
        dp[1] = s1[0]*m[s1[0]];
        for(int i =2;i<=n;i++)
        {
            int ans = s1[i-1]*m[s1[i-1]];
            if(s1[i-1] == (s1[i-2] + 1))
            {
                ans += dp[i-2];
            }
            else{
                ans += dp[i-1];
            }
            dp[i] = max(dp[i-1] , ans);
        }
        return dp[n];
    }
    };