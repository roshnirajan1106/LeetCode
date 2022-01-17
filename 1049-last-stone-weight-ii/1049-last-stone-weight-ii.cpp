class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(auto p : stones)
            sum += p;
        
        int  n = stones.size();
       vector<int> dp(sum+1,0);
        dp[0]=1;
       
        for(auto p : stones)
        {
            for(int j = sum ;j>=p;j--)
            {
                if(p == j || dp[j-p])
                {
                    dp[j] =1;
                }
            }
        }
        cout<<sum<<endl;
        for(int i = 0 ; i <= sum ;i++)
            if(dp[i] == 1)
                cout<<i<<" ";
        int min_sum = INT_MAX;
        for(int i = 0;i <=sum/2;i++)
        {
            if(dp[i] == 1)
                min_sum= min(sum - 2*i,min_sum);
        }
        return min_sum;
    }
};