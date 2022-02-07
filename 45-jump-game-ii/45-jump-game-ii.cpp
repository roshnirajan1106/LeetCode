class Solution {
public:
    int jump(vector<int>& nums) {
        int s =0;
        int n = nums.size();
        int jump = nums[0];
        if(n == 1)
            return 0;
        int step =0;
        if(nums[0] >= n-1)
            return 1;
        while(s < n)
        {   
            int reach = 0;
            for(int i = s+1;jump-- && i <n-1 ;i++)
            {
                if(reach < nums[i] + i)
                {
                    s= i;
                    reach = nums[i]+i;
                }
            }
            step++;
            if(reach >= n-1)
                return step + 1;
            
            jump = nums[s];
        }
        return -1;
    }
};