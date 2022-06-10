class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int st = -1;
        map<int,int>m;
        int ans = 0;
        for(int i = 0;i<s.length();i++)
        {
            if(m.find(s[i]) == m.end())
            {
                m[s[i]] = i;
            }
            else 
            {
                ans = max(ans,i-st-1);

                if(st < m[s[i]])
                    st = m[s[i]];
                
                m[s[i]] = i;
            }
                
        }
        int len = s.length()-1-st;
        
        return max(len,ans);
    }
};