class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      int n = nums.size();
        if(n == 1)
            return 0;
        
        map<int,int>m;
        m[0] = -1;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] == 0)
                nums[i] = -1;
        }
        for(int i = 1;i<n ;i++)
        {
            nums[i] += nums[i-1];
            
        }
        int ans = 0;
        int max_len=0;
        for(int i = 0;i<n;i++)
        {
            if(m.find(nums[i]) == m.end())
                m[nums[i]] =i;
            else{
                max_len = i - m[nums[i]] ;
                ans= max(ans,max_len);
            }
        }
        return ans ;
        
    }
    
};