class Solution {
public:
    void sub(set<vector<int>> &res, vector<int>ans, vector<int>&nums,int i, int n)
    {
        if(i == n)
        {
            res.insert(ans);
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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         set<vector<int>>res;
        vector<int> ans;
        int n = nums.size();
        sub(res,ans,nums,0,n);
        vector<vector<int>> anss;
        for(auto p : res)
            anss.push_back(p);
       
        return anss;
    }
};