class Solution {
public:
    void para(int countopen,int countclose,int n, string &res,vector<string>&ans)
    {
        if(countclose == n)
        {
            ans.push_back(res);
                return ;
        }
        if(countopen < n)
        {
            res.push_back('(');
            para(countopen+1,countclose,n,res ,ans);
            res.pop_back();
        }
            
        if(countclose < countopen)
        {
            res.push_back(')');
            para(countopen, countclose+1,n,res ,ans);
            res.pop_back();
        }
        
        
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string res="";
        para(0,0,n,res,ans);
        return ans;
    }
};