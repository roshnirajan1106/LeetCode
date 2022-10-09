class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int close = nums[0] + nums[1] + nums[2];
        for(int i= 0 ;i<nums.size();i++)
        {
            int sum = 0;
            int lo = i+1;
            int hi = nums.size()-1;
            while(lo < hi)
            {
                sum = nums[i] + nums[lo] + nums[hi];
                if(abs(target-close) > abs(target- sum))
                {
                    close = sum;
                }
                if(target == sum)
                {
                    return target;
                }
                else if(sum > target)
                {
                   hi--;
                }
                else
                    lo++;
                
            }
        }
        return close;
    }
};