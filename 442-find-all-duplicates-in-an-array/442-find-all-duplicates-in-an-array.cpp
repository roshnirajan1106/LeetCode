class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>output;
        for(int i = 0;i<nums.size();i++){
            int x = abs(nums[i])-1;
            if(nums[x] < 0)
            {
                output.push_back(x+1);
                 
            }
            nums[x] =-1*nums[x];
            
        }
        return output;
    }
};