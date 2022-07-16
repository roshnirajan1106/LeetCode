class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>csum;
        vector<int>res;
        for(int i = 0;i<nums.size();i++)
        {
            int rem = target - nums[i];
            if(csum.find(rem) != csum.end())
            {
                res.push_back(csum[rem]);
                res.push_back(i);
                break;
            }
            csum[nums[i]] = i;
                
        }
        return res;
    }
};