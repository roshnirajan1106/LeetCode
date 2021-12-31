class Solution {
public:
   static bool comp(string w1, string w2)
   {
       return w1.length() < w2.length();
   }
    int longestStrChain(vector<string>& words) {
      sort(words.begin(),words.end(),comp);
       
        map<string,int> dp;
        int max_len = 1;
        for(auto p :words)
        {
            
        
            string temp;
            int ans = 0;
            for(int i = 0 ;i<p.length();i++)
            {   
                temp = p.substr(0,i) + p.substr(i+1);
                if(dp.find(temp) != dp.end())
                    ans = max(ans, dp[temp] );
            }
            dp[p] = ans + 1;
            max_len = max(max_len, dp[p]);
            
            
        }
        
        return max_len;
    }
};