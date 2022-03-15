class Solution {
public:
    string minRemoveToMakeValid(string s) {
        map<int,int>m;
        stack<pair<char,int>>str;
        
        for(int i = 0;i<s.length();i++)
        {
            if(s[i] == '(')
                str.push({s[i],i});
            else  if(s[i] == ')')
            {
                if(!str.empty() && str.top().first == '(')
                {
                    //cout<<str.top().second<<" "<<i<<endl;
                    m[str.top().second] = 1;
                    m[i] = 1;
                    str.pop();
                }
            }
        }
        for(auto p :m)
        {
            cout<<p.first<<" "<<p.second<<endl;
        }
        string ans = "";
        for(int i = 0;i<s.length();i++)
        {
            if(s[i] == '(' || s[i]== ')' )
            {
                if(m.find(i) != m.end())
                    ans += s[i];
            }
               
            else 
                ans +=s[i];
        }
        return ans;
    }
};