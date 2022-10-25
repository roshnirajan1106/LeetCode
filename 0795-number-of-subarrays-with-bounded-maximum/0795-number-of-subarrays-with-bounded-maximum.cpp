class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int s = 0;
        int cnt =0;
        int prev = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] >= left && nums[i] <=right)
            {
                prev = i - s + 1;
                cnt += prev;
            }
            else if(nums[i] < left)
            {
                cnt += prev;
            }
            else{
                s = i +1;
                prev = 0;
            }
        }
        return cnt;
    }
};