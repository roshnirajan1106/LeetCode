class Solution {
public:
    bool canConstruct(string s, int k) {
        map<char,int>m;
        if(s.length() < k)
            return false;
        for(auto p : s)
        {
            m[p]++;
        }
        int count =0;
        for(auto p : m)
        {
            if(p.second % 2 == 1)
                count++;
        }
        if(count > k)
            return false;
        
        return true;
    }
};