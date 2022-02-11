class Solution {
public:
 
    bool checkInclusion(string s1, string s2) {
        int m= s1.length();
        int n =s2.length();
        if(m > n)
            return false;
       
        if(s1 == s2)
            return true;
        
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for(int i = 0 ;i<s1.length();i++)
        {
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        if(v1 == v2)
            return true;
        
        for(int i = m;i<n;i++)
        {
            int del = i - m;
            v2[s2[del]-'a']--;
            cout<<"deleting "<<s2[del]<<endl;
            v2[s2[i]-'a'] ++;
            cout<<"inserting "<<s2[i]<<endl;
            if(v1 == v2)
                return true;
        }
        return false;
    }
};