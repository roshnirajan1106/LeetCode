class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      map<int,int> m;
        m[0] = 1;
        for(int i =1;i<nums.size();i++)
            nums[i] +=nums[i-1];
        
        int ans = 0;
        for(int i = 0;i<nums.size();i++)
        {
            int diff = nums[i] - k;
            if(m.find(diff) != m.end())
            {
                ans += m[diff];
                
            }
            if(m.find(nums[i]) == m.end())
                m[nums[i]] = 1;
            else
                m[nums[i]]++;
        }
        return ans;
        
    }
};