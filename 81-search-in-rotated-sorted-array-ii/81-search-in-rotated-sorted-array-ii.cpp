class Solution {
public:
    bool search(vector<int>&nums,int target,int s, int e)
    {
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            
            if(nums[mid] == target)
                return true;
            
            else if(nums[mid] < target)
            {
                s = mid+1;
            }
            else
                e = mid-1;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int k = 0;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] < nums[i-1])
                k = i-1;
            }
        
        int e = nums.size()-1;
        bool ans1 = search(nums,target,0,k);
        bool ans2 = search(nums,target,k+1,e);
        
        
        return ans1 | ans2;
    }
};