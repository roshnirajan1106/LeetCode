class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int>m;
        char c;
        for(int i = 0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        for(int i = 0;i<t.length();i++)
        {
            if(m.find(t[i]) == m.end() || m[t[i]] == 0)
            {
                c = t[i];
                break;
            }
            else
                m[t[i]] --;
        }
        return c;
    } 
};