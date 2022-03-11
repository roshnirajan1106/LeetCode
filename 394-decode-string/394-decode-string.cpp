class Solution {
public:
    string decode(string s,int &i)
    {
        string ans = "";
        while(i < s.length() && s[i] != ']')
        {
            if(s[i] >= 'a' && s[i] <='z')
                ans +=s[i++];
            else{
                int n = 0;
                if(s[i] >= '0' && s[i] <= '9')
                {
                    while(s[i] >='0' && s[i] <='9')
                        n =n *10 + (s[i++]-'0');
                    
                }
                i++;
                string t= decode(s,i);
                i++;
                while(n--)
                    ans += t;
                
                
            }
            
        }
        return ans;
    }
    string decodeString(string s) {
        int i =0;
        return decode(s,i);
    }
};