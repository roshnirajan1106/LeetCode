class Solution {
public:
    int dun(vector<vector<int>>&dp, int i ,int j, int m ,int n,vector<vector<int>>& dungeon)
    {
     if(i > m-1 || j >n-1)
         return INT_MAX;
        if(i == m-1 && j== n-1)
        {
            return (dungeon[i][j] <=0 ? -dungeon[i][j] +1 :1);
        }
        if(dp[i][j] != INT_MAX)
            return dp[i][j];
        
        int down = dun(dp,i+1,j, m,n, dungeon);
        int right = dun(dp,i,j+1,m,n, dungeon);
        int ans = min(down, right) - dungeon[i][j];
        dp[i][j] = (ans <=0 ? 1 : ans);
        return dp[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
       vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
        return dun(dp, 0,0,m,n,dungeon);
    }
};