class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int i = 0;
    for (auto p : nums)
        if (i < 2 || p > nums[i-2])
            nums[i++] = p;
    return i;
    }
};