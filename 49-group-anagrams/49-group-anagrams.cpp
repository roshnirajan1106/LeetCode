class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(auto p : strs)
        {
            string x = p;
            sort(x.begin(),x.end());
            mp[x].push_back(p);
        }
        vector<vector<string>>output;
        for(auto p : mp)
        {
            output.push_back(p.second);
            
        }
        return output;
    }
};