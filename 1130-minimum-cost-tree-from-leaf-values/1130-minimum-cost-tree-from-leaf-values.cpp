class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(n,{INT_MAX,INT_MAX}));
        for(int gap = 0; gap<n;gap++)
        {
            for(int i = 0, j = gap ; j<n;j++,i++)
            {
                if(gap == 0)
                {
                    dp[i][j].first = arr[i];
                    dp[i][j].second= arr[i];
                    
                }
                if(gap == 1)
                {
                    dp[i][j].first= arr[i]*arr[j];
                    dp[i][j].second = max(arr[i],arr[j]);
                }
                else{
                    int sum = 0 ;
                    for(int k = i;k<j;k++ )
                    {
                        sum = dp[i][k].second * dp[k+1][j].second;
                        if(i != k)
                            sum += dp[i][k].first;
                        if(k+1 != j) 
                            sum += dp[k+1][j].first;
                        
                        if(sum  < dp[i][j].first)
                        {
                            dp[i][j].first =sum;
                            dp[i][j].second = max(dp[i][k].second, dp[k+1][j].second);
                        }
                            
                    }
                }
                
            }
        }
        for(int i = 0 ; i< n ; i ++)
        {
            for(int j = 0;j <n;j++)
            {
                cout<<dp[i][j].first<<","<<dp[i][j].second<<" ";
            }
            cout<<endl;
        }
        return dp[0][n-1].first;
    }
};