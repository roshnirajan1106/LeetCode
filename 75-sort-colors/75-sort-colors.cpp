class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s= -1;
        int e = nums.size();
        int i = 0;
        while(i < e)
        {
            if(nums[i] == 0)
            {
                s++;
                swap(nums[s],nums[i]);
                i++;
            }
            else if(nums[i] == 2)
            {
                e--;
                swap(nums[e],nums[i]);
                
            }
            else
                i++;
        }
    }
};