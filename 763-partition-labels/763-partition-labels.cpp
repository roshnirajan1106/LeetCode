class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>nums(26,0);
        for(int i = 0; i<s.length();i++)
        {
            int n = s[i]-'a';
            nums[n] = i;
        }
        for(auto p :nums)
            cout<<p<<" ";
        int i = 0;
        vector<int>res;
        int n = s.length();
        while(i < n)
        {   
            int num =  s[i] -'a';
            int max_i = nums[num];
            int j = i+1;
            while(j < max_i)
            {
                 num = s[j]-'a';
                max_i = max(max_i,nums[num]);
                j++;
                
            }
            res.push_back(max_i-i+1);
            i = max_i + 1;
            
        }
        return res;
        
    }
};