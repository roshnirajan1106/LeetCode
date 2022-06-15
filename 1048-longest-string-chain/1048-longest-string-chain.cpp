class Solution {
public:
   static bool cmp(string s1,string s2)
   {
       if(s1.length() < s2.length())
           return true;
       return false;
   }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        
        int n = words.size();
        cout<<n<<endl;
        map<string,int>dp;
        dp[words[0]]= 1;
        int res = 1;
        for(int i = 1;i<n;i++)
        {
            string s = words[i];
            
            int len = words[i].length();
            cout<<s<<" -- >";
            int ans = 0;
            for(int j = 0;j<len;j++)
            {
                string str = s.substr(0,j) + s.substr(j+1,len);
                cout<<str<<" ,";
                if(dp.find(str) != dp.end())
                {
                    ans = max(ans,dp[str]);
                }
                
            }
            cout<<endl;
            dp[s] = 1 + ans;
            res = max(res,dp[s]);
        }
        
        return res;
    }
};