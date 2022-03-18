class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int>m;
        map<char,int>vis;
        for(auto p :s)
        {
            m[p] ++;
            vis[p] =0;
        }
        
        stack<char>str;
       
        for(int i =0;i<s.length();i++)
        {
            while(!str.empty() && vis[s[i]] == 0 &&  str.top() > s[i] && m[str.top()] > 0 )
            {
                vis[str.top()] = 0;
               str.pop();
                
            }
            if(vis[s[i]] == 0)
                str.push(s[i]);
            
            vis[s[i]] =1;
            m[s[i]]--;
        }
        string ans ="";
        while(!str.empty())
        {
            ans += str.top();
            str.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};