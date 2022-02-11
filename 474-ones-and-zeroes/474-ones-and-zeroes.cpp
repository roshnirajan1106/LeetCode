class Solution {
public:
    
    int find(vector<pair<int,int>>& nums, int i ,int size,int m,int n,int dp[601][101][101])
    {
        if(m < 0 || n < 0)
            return -1;
        if(i == size)
            return 0;
         if(dp[i][m][n] != -1)
             return dp[i][m][n];
        //inc
        int inc = 1 + find(nums,i+1,size,m-nums[i].second, n-nums[i].first,dp);
          
        int exc = find(nums,i+1,size, m,n,dp);
           return dp[i][m][n]= max(inc, exc);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>nums;
        int dp[601][101][101];
        memset(dp,-1,sizeof(dp));
        
        for(int i = 0;i<strs.size();i++)
        {
            //count 1
            int one  = 0, zero = 0;
            for(int j = 0;j<strs[i].size();j++)
            {
                if(strs[i][j] == '1')
                    one++;
                else
                    zero++;
            }
            nums.push_back({one,zero});
        }
    
        return find(nums,0,strs.size(),m,n,dp);
    }
    
};