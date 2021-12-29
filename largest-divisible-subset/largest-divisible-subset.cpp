class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      sort(nums.begin(), nums.end());
    int n = nums.size();
        vector<int> dp(n,0);
        vector<int> parent(n,0);
        dp[0]= 1;
        int max_idx = 0;
        int maximum = 0;
        parent[0] = 0;
        for(int i = 1;i<n;i++)
        {   int ans = 0;
            int p = i;
            for(int j = 0;j<i;j++)
            {
               if(nums[i] % nums[j] == 0)
               {    
                   if(ans < dp[j])
                   {
                       ans = dp[j];
                       p = j;
                   }
                   
               }
            }
            dp[i] = ans  + 1;
            
            parent[i] = p;
         cout<<nums[i]<<" "<<dp[i]<<" "<<p<<endl;
            if(maximum < dp[i])
            {
                maximum = dp[i];
                max_idx = i;
            }
        }
        vector<int> res;
        while(parent[max_idx] != max_idx)
        {
            res.push_back(nums[max_idx]);
            max_idx = parent[max_idx];
        }
        res.push_back(nums[max_idx]);
        return res;
      
    }  
};