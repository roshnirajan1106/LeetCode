class Solution {
public:
    void sub(vector<vector<int>> &res, vector<int>ans, vector<int>&nums,int i, int n)
    {
        if(i == n)
        {
            res.push_back(ans);
            return ;
        }
        
        //inc;
        ans.push_back(nums[i]);
        sub(res,ans,nums,i+1,n);
        //no include
        ans.pop_back();
        sub(res,ans, nums,i+1,n);
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int> ans;
        int n = nums.size();
       sub(res,ans,nums,0,n);
        return res;
    }
};