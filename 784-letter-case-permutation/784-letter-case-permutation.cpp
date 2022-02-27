class Solution {
public:
    void func(vector<string> &ans , string str , int i  , int n,string s  )
    {
        if(i == n)
        {
            ans.push_back(str);
            return ;
        }
            
        
        char idx = s[i];
        //cout<<idx<<endl;
        if(idx >= '0' && idx <= '9')
            return func(ans,str + idx,i+1,n,s);
        
        char ch = toupper(idx);
        //cout<<ch<<endl;
        func (ans ,str + ch, i+1,n,s);
        ch  = tolower(idx);
        //cout<<ch<<endl;
        func(ans, str + ch, i+1,n,s);

        
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string str = "";
        int n = s.length();
        func(ans, str,0,n,s);
        return ans;
    }
};