class Solution {
public:
    bool find(int i,int j,string &s,int &count)
    {
        if(i >= j )
            return true;
        
        if(s[i] == s[j])
        {
            return find(i+1,j-1,s,count);
        }
        
            count++;
            
            if(count > 1)
                return false;
            
            int ans1 = find(i+1,j,s,count);
            int ans2 = find(i,j-1,s,count);
            return ans1 || ans2;
        
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        int count = 0;
        return find(i,j,s,count);
    }
};