class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        stack<char>s2;
        for(auto p : s)
        {
            if(p == '#' && !s1.empty())
                s1.pop();
            else if(p != '#')
                s1.push(p);
        }
        for(auto q : t)
        {
            if(q == '#' && !s2.empty() )
                s2.pop();
            else if(q != '#')
                s2.push(q);
        }
        
        if(s1 == s2)
            return true;
        
        return false;
        
        
    }
};