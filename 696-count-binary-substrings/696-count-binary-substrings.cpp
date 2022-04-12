class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int>num;
        
        int count = 1;
        for(int i = 1;i<s.length();i++){
            if(s[i] ==s[i-1] )
            {
                count++;
            }
            else{
                num.push_back(count);
                count = 1;
            }
        }
        num.push_back(count);
        int sum = 0;
        for(int i = 1;i<num.size();i++){
            sum += min(num[i],num[i-1]);
            
        }
        return sum;
    }
};