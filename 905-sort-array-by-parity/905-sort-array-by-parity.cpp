class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int s  = -1;
        for(int i  =0;i<nums.size();i++)
        {
            if(nums[i] % 2 == 0)
            {
                s = s + 1;
                swap(nums[i],nums[s]);
                
            }
        }
        
        return nums;
    }
};