class Solution {
public:
    string removeDuplicates(string s, int k) {
        pair<char,int>p ;
        p.first = s[0];
        p.second= 1;
        stack<pair<char,int>>str;
        str.push(p);
        for(int i =1;i<s.length();i++)
        {
            if(!str.empty() && s[i] == str.top().first)
            {
                p = make_pair(s[i],str.top().second + 1);
                str.pop();
                str.push(p);
                
            }
            else
                str.push({s[i],1});
            
            if(!str.empty() && str.top().second == k)
                str.pop();
        }
        
        string res ="";
        string x ="";
        while(!str.empty())
        {
            x.append(str.top().second, str.top().first);

            res +=x ;
            x="";
            str.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};