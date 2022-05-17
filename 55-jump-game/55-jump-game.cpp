class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        int i = 0;
        int n = nums.size();
        while(i<n)
        {
            if(i > reach)
                return false;
            if(reach >= n-1)
                return true;
            
            reach= max(reach, nums[i] + i);
                i++;
            
        }
        return false;
    }
};