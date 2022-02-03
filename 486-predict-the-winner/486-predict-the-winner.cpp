class Solution {
public:
    int find_the_winner(vector<int>& nums,int i, int j,bool turn,int dp[21][21][2])
    {
        if(i > j)
            return 0;
        if(dp[i][j][turn] != -1)
            return dp[i][j][turn];
        int ans ;
        if(turn)
        {
            int a =nums[i] +  find_the_winner(nums,i +1,j,false,dp );
            int b = nums[j] +find_the_winner(nums,i,j-1,false,dp);
            return dp[i][j][turn] =  max(a,b);
        }
        
            int a = -nums[i] + find_the_winner(nums,i+1,j,true,dp);
            int b = -nums[j] + find_the_winner(nums,i,j-1,true,dp);
            return dp[i][j][turn] =  min(a,b);
    
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int dp[21][21][2];
        memset(dp,-1,sizeof(dp));
        int ans = find_the_winner(nums,0,n-1,true,dp);
        cout<<ans<<endl;
        return (ans < 0 ? false:true);
    }
};