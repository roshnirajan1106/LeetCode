class Solution {
public:
    vector<string> arr = {"/","/","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void letter(vector<string>&res,string s, int i , int n, string ans)
    {
        if(i == n)
        {
            if(ans !="")
                res.push_back(ans);
            return ;
        }
        for(auto p : arr[s[i] -'0'])
        {
            letter(res,s,i+1,n,ans+p);
        }
            
    }
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        int i = 0;
        int n = digits.length();
        string ans="";
        
        letter(res,digits,i,n,ans);
        return res;
    }
};