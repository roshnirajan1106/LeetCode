class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n+1,0);
        for(auto p:nums)
        {
            if(p < 0 || p > n)
                continue;
            
            arr[p] = 1;
        }
        
        for(int i = 1;i<=n;i++)
        {
            if(arr[i] == 0)
                return i;
        }
        return n+1;
    }
};