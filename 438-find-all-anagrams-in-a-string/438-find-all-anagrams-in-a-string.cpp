class Solution {
public:
   
    vector<int> findAnagrams(string s, string p) {
         vector<int>out;
        if(p.length() > s.length())
            return out;
        if(p == s)
        {
            out.push_back(0);
            return out;
        }
            
        map<char,int> anagrams;
        map<char,int> check;
        for(auto q : p)
        {
            anagrams[q]++;
            check[q] =0;
        }
        
        for(int i = 0;i<p.length();i++)
        {
            if(check.find(s[i]) != check.end())
            {
                check[s[i]] ++;
            }
        }
        if(check == anagrams)
        {
            out.push_back(0);
            cout<<0<<endl;
            
        }
        for(int i = p.length();i<s.length();i++)
        {   //cout<<"removing "<<s[i-p.length()]<<endl;
            if(check.find(s[i - p.length()]) != check.end())
                check[s[i-p.length()]]--;
            //cout<<"adding "<<s[i]<<endl;
            if(check.find(s[i]) != check.end())
            {
                check[s[i]]++;
                //cout<<check[s[i]]<<endl;
            }
                
                      
            
            if(check == anagrams)
            {
                out.push_back(i - p.length() + 1);
                cout<<i - p.length() + 1;
            }
                    
        }
        return out;
    }
};