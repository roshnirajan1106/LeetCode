class Solution {
public:
    vector<int> partitionLabels(string s) {
        int start = 0;
        int end =0;
        int i =0;
        vector<int>res;
        map<char,int>m;
        for(int i = 0;i<s.length();i++)
            m[s[i]] = i;
            
        while(i < s.length())
        {
            end = max(end,m[s[i]]);
            if(i == end)
            {
                int size = end- start + 1;
                res.push_back(size);
                start = i+1;
                
            }
            i++;
        }
        return res;
    }
};