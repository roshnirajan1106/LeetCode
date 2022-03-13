class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int>nums;
        for(int i =1;i<n;i++)
        {
            nums.push_back(i);
            fact = fact *i;
        }
        nums.push_back(n);
        string s = "";
        k--;
        while(true)
        {
            char str = nums[k/fact] + '0';
            s = s + str;
            nums.erase(nums.begin() + k/fact);
            if(nums.size() == 0)
                break;
            
            k = k%fact;
            fact= fact/nums.size();
        }
        return s;
    }
};