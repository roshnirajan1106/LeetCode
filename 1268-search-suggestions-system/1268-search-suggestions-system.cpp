class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        int n = searchWord.length();
        vector<vector<string>>ans(n);
        for(int i = 0;i< searchWord.length();i++)
        {
            string s1 = searchWord.substr(0,i+1);
           
            for(int j = 0;j<products.size();j++)
            {
                string s2 = products[j].substr(0,i+1);
                
                if(s1 == s2 && ans[i].size()<3)
                {
                    ans[i].push_back(products[j]);
                }
            }
            cout<<endl;
        }
        return ans;
    }
};