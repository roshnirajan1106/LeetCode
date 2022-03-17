class Solution {
public:
    void permutations(int i,int n,vector<vector<int>>&ans,vector<int>& nums)
    {
        if(i == n)
        {
            ans.push_back(nums);
            return ;
        }
        for(int j = i;j<n;j++)
        {
            swap(nums[j],nums[i]);
            
            permutations(i+1,n,ans,nums);
            swap(nums[j],nums[i]);
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int i  =0;
        int n = nums.size();
        permutations(i,n,ans,nums);
        return ans;
    }
};