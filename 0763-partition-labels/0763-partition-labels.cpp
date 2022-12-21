class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>m;
        vector<int>ans;
        int start = 0;
        for(int i = 0;i<s.length();i++)
        {
            m[s[i]] = i;
        }
        int max_count = 0;
        for(int i = 0;i<s.length();i++)
        {
            if(i > max_count)
            {
                cout<<max_count-start +1 <<endl;
                ans.push_back(max_count-start+1);
                start = i;
            }
            max_count = max(max_count,m[s[i]]);
            
            
        }
        ans.push_back(max_count-start+1);
        return ans;

    }
};