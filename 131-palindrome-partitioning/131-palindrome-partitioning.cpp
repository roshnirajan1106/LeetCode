class Solution {
public:
    bool isPalindrome(string s)
    {   int i = 0;
        int j = s.length()-1;
        while(i < j)
        {
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }
        return true;
    }
    void find_the_palindromes(int s,  string str, int n, vector<string>&out, vector<vector<string>>&ans)
    {
        if(s == n)
        {
            ans.push_back(out);
            return ;
        }
        for(int i = s;i<n;i++)
        {
            string sub=  str.substr(s, i-s+1);
            if(isPalindrome(sub))
            {
                out.push_back(sub);
                find_the_palindromes(i+1, str, n,out, ans);
                out.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<string>out;
        vector<vector<string>>ans;
        
      
        int n = s.length();
        find_the_palindromes(0, s, n,out, ans);
        return ans;
    }
};