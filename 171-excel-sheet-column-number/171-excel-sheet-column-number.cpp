class Solution {
    
public:
    int soln(string str,int n, int i)
    {
        if(i == n-1)
            return str[i]-'A' + 1;
        
        double ans = pow(26,n-i-1);
        int res = ans*(str[i]-'A' + 1);
        return res + soln(str,n,i+1);
        
    }
    int titleToNumber(string columnTitle) {
        int n=columnTitle.length();
        return soln(columnTitle,n,0);
    }
};