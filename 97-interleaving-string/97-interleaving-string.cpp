class Solution {
public:
    bool Issub(int i,int j,int k, string&s1,string &s2,string &s3,int dp[101][101][201]){
        if(i == s1.length() )
            return dp[i][j][k] =  s2.substr(j,s2.length()) == s3.substr(k,s3.length());
        if(j == s2.length())
            return dp[i][j][k] = s1.substr(i,s1.length()) == s3.substr(k,s3.length());
        
        if(dp[i][j][k]  != -1)
            return dp[i][j][k];
        if(s1[i] == s3[k] && s2[j] == s3[k])
        {
            return dp[i][j][k] = Issub(i+1,j,k+1,s1,s2,s3,dp) || Issub(i,j+1,k+1,s1,s2,s3,dp);
        }
        else if(s1[i] == s3[k])
        {
            return dp[i][j][k] = Issub(i+1,j,k+1,s1,s2,s3,dp);
        }
        else if(s2[j] == s3[k])
            return dp[i][j][k]= Issub(i,j+1,k+1,s1,s2,s3,dp);
        
        return dp[i][j][k] = false;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        // aadbbcbcac
        int dp[101][101][201];
        memset(dp,-1,sizeof(dp));
        return Issub(0,0,0,s1,s2,s3,dp);
        
    }
};