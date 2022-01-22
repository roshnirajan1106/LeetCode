class Solution {
public:
    int find_the_minimum(vector<int>&arr,vector<vector<int>>&dp, int n,int flag, int i, int j){
        if(i > j)
            return 0 ;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(flag)
        {
             int ans1 = find_the_minimum(arr,dp,n,0,i+1 ,j);
             int ans2 = find_the_minimum(arr, dp,n,0,i,j-1);
            dp[i][j] = max(arr[i] + ans1, arr[j]+ans2);
            
        }
        else{
            int ans1 = find_the_minimum(arr,dp,n,1,i+1 ,j);
            int ans2 = find_the_minimum(arr, dp,n,1,i,j-1);
            dp[i][j] = min(-arr[i]+ans1, -arr[j]+ans2);
        }
        return dp[i][j];
    }
    bool stoneGame(vector<int>& arr) {
        int n = arr.size();
        int alice=0;
        int bob = 0;
        int flag = 1;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int x =  find_the_minimum(arr, dp, n, 1, 0,0);
     
        return x >0;
    }
};