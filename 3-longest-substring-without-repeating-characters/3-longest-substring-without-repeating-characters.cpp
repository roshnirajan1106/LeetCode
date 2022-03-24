class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        map<char,int>m;
        int max_len = -1;
        for(int i = 0; i<s.length();i++)
        {
            if(m.find(s[i]) == m.end())
            {
                m[s[i]] = i;
            }
            else{
                if(start <= m[s[i]])
                {
                    int d = i -start;
                    cout<<"distance "<<d<<endl;
                    max_len =  max(max_len,d);
                    start = m[s[i]] + 1;
                    cout<<start<<endl;
                    m[s[i]] = i;
                }
                else{
                    m[s[i]] = i;
                    continue;
                }
            }
        }
        int d = s.length() - start;
        return max(max_len,d);
        
        
    }
};