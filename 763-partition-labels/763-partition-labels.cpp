class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>num(26,-1);
        for(int i = 0;i<s.length();i++)
        {
            int ch = s[i] - 'a';
            num[ch]= i;
        }
        int i = 0;
        vector<int> res;
        while(i < s.length())
        {   
            int last_i = 0;
            int size = 0;
            int element = s[i]-'a';
            cout<<s[i]<<" : "<<num[element]<<endl;
            last_i = num[element];
            for(int j = i;j<= last_i ; j++)
            {   
                
                int p = s[j] - 'a';
                last_i = max(last_i, num[p]);
            }
            size = last_i - i + 1;
         res.push_back(size);
            i = last_i+1;
            
           
            
        }
        return res;
    }
};