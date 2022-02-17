class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n = s1.length();
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool ans = true;
        
        for(int i = 0 ; i<n;i++)
        {
            if(s2[i] > s1[i])
            {
                ans =false;
                break;
            }
        }
        bool ans1 = true;
        for(int i = 0 ; i<n;i++)
        {
            if(s1[i] > s2[i])
            {
                ans1 =false;
                break;
            }
        }
        return ans | ans1;
        
    }
};