class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for(auto p : nums)
        {
            if(p  % 2 == 0)
                sum += p;
        }
        vector<int>ans;
        for(auto p : queries)
        {
            int idx = p[1];
            int val = p[0];
            int x = nums[idx] + val;
            cout<<x<<endl;
            if(nums[idx] % 2 == 0)
            {
                sum -= nums[idx];
            }
            if(x  % 2 == 0)
            {
                sum += x;
            }
            nums[idx] = x;
            ans.push_back(sum);
        }
        return ans;
    }
};