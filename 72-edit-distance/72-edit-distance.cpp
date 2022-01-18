class Solution {
public:
    int minDistance(string text1, string text2) {
      //deleting means , ab convert it into a   
        //for deleteing 1 + dp(a)(a);
        //for replacing means  ab -> ac 
        //for replacing  1 + dp(a)(a)
        //ab converts ->a == aba and convert ab => " "
        int m = text2.size();
        int n = text1.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i = 0 ; i < m +1 ; i++)
        {
            dp[i][0] = i;
        }
        for(int j = 0 ; j < n+1;j++)
            dp[0][j] = j;
        
        for(int i = 1; i< m+1;i++)
        {
            for(int j = 1 ; j < n +1 ;j ++)
            {
                if(text2[i-1] == text1[j-1])
                    dp[i][j] =  dp[i-1][j-1];
                else{
                    dp[i][j]= 1 + min(dp[i-1][j-1] ,min(dp[i-1][j] , dp[i][j-1]));
                }
            }
        }
        return dp[m][n];
    }
};