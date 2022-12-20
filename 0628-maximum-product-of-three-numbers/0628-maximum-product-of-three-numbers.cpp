class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = nums[0]*nums[1]*nums[n-1];
        int right =  nums[n-1]*nums[n-2]*nums[n-3];
        return max(left,right);
        
    }
};