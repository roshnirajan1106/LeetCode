class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.length()-1;
        for(int i = 0,j = n; i<j;i++,j--)
        {
            if(s[i] != s[j]) return 2;
            
        }
        return 1;
    }
};