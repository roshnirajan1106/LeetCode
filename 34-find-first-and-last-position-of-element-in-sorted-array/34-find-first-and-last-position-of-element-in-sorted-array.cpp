class Solution {
public:
    int find(int target,vector<int>nums)
    {
        int mid = nums.size();
        int c = 0;
        int s= 0;
        int e = mid-1;
        int ans  = nums.size();
        while(s<=e)
        {
            int mid  = s + (e-s)/2;
            
            if(target<= nums[mid])
            {

                ans = mid;
                e = mid-1;
            }
                
            else
                s = mid + 1;
        }
        return ans;
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        if(nums.size() == 0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int s = find(target,nums);
        int e = find(target+1,nums);
        if(s == nums.size() || nums[s] != target)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(s);
            ans.push_back(e-1);
            return ans;
        
        
        
    }
};