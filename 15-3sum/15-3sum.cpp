class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i = 0;i<nums.size()-2;i++)
        {
            if(i == 0 || nums[i-1] != nums[i] )
            {
                int sum = -1*nums[i];
                int lo = i+1;
                int high = nums.size()-1;
            
                 while(lo<high)
                {
                    vector<int>res;
                    int s = nums[lo] + nums[high];
                    if(s == sum)
                    {
                        res.push_back(nums[lo]);
                        res.push_back(nums[high]);
                        res.push_back(nums[i]);
                        ans.push_back(res);
                        while(lo < high && nums[lo] == nums[lo+1])lo++;
                        while(lo < high && nums[high] == nums[high-1] ) high--;
                        lo++;
                        high--;
                    }
                    else if(s < sum)
                        lo++;
                     else
                         high--;
                }
            }
            
        }
        return ans;
    }
};