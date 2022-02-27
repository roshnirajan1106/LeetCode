class Solution {
public:
    void para(int count_of_open,int count_of_close,string str, vector<string> & ans, int n)
    {
        if(count_of_open > n)
            return ;
        if(count_of_close == n)
        {
            ans.push_back(str);
            return ;
        }
        if(count_of_open > count_of_close)
            para(count_of_open, count_of_close +1 , str + ')' , ans, n);
        para(count_of_open + 1,count_of_close, str + '(' , ans, n);
    }
    vector<string> generateParenthesis(int n) {
        int count_of_open = 0;
        int count_of_close= 0;
        string str = "";
        vector<string> ans;
        para(count_of_open,count_of_close, str, ans,n);
        return ans;
    }
};