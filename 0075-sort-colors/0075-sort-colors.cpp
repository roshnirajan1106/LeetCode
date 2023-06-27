class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0 ;
        int hi = nums.size()-1;
        int i = 0;
        while(lo <= hi && i <= hi)
        {
            if(nums[i] == 0)
            {
                swap(nums[lo],nums[i]);
                lo++;
                i++;
            }
            else if(nums[i] == 2){
                swap(nums[hi],nums[i]);
                hi--;
                
            }
            else{
                i++;
            }
        }
        
    }
};