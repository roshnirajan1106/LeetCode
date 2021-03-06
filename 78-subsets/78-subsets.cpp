class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int p = 1 << n;
        vector<vector<int>>res(p);
        for(int i = 0;i<p;i++)
        {
            for(int j =0 ;j<n;j++)
            {
                if(i & (1 <<j ))
                {
                    res[i].push_back(nums[j]);
                }
            }
        }
        vector<int>empty;
        res[0]= empty;
        return res;
    }
};