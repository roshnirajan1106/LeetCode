class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans = 0;
        sort(tokens.begin(),tokens.end());
        int cnt= 0;
        if(tokens.size() == 0)
            return 0;
        if(power < tokens[0] )
            return 0;
        int s= 0;
        int e = tokens.size()-1;
        while(s <= e)
        {
          if(tokens[s] > power)
          {
              power += tokens[e];
              e--;
              cnt--;
          }
           else if(tokens[s] <= power)
           {
               power -= tokens[s];
               cnt++;
               ans = max(ans, cnt);
               s++;
           }
        }
        return ans;
    }
};