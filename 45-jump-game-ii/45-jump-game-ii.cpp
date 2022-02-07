class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 1;
        int last_jump  = nums[0];
        int n = nums.size();
        if(n == 1)
            return 0;
        int i = 1;
        int max_reach=0;
        while(last_jump < n-1)
        {
            max_reach = max(max_reach,nums[i] + i );
            if(i == last_jump)
            {
                last_jump = max_reach;
                step++;
            }
            i++;
        }
        return step;
    }
};