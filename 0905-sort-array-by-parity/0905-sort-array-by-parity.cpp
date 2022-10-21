class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        for(int k = 0;k<=j;k++)
        {
            if(nums[k] % 2 == 0)
                swap(nums[i++],nums[k]);
            else
                swap(nums[j--] ,nums[k--]);
        }
        return nums;
    }
};