class Solution {
public:
    void permutation(string s, int i,vector<string>&res)
    {
        if(i == s.length() )
        {
            res.push_back(s);
            return ;
        }
        for(int j = i;j<s.length();j++)
        {
            swap(s[i],s[j]);
            permutation(s,i+1,res);
            swap(s[i],s[j]);
        }
            
    }
    string getPermutation(int n, int k) {
        string s = "";
        for(int i =1;i<=n;i++)
        {
            s += i +'0';
        }
        vector<string>res;
        
        k--;
        int fact = 1;
        for(int i =1;i<n;i++)
            fact =fact*i;
        if(k >= fact)
        {
            int rem = k /fact;
            swap(s[rem],s[0]);
            k = k-fact*rem;
        }
        permutation(s,1,res);
        sort(res.begin(),res.end());
        
        return res[k];
    }
};