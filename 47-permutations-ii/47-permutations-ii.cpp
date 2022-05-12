class Solution {
public:
    void permute(vector<vector<int>>&ans,vector<int>&res,int n ,int i,map<int,int>&m)
    {
        if(i == n)
        {
            ans.push_back(res);
            return ;
        }
        for(auto p : m)
        {
            if(p.second == 0)
            {
                continue;
            }
            res.push_back(p.first);
            m[p.first] --;
            permute(ans,res,n,i+1,m);
            res.pop_back();
            m[p.first] ++;
            
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int,int>m;
        for(auto p :nums)
        {
            m[p]++;
        }
        
        int i = 0;
        int n= nums.size();
        vector<vector<int>>ans;
        vector<int>res;
        permute(ans,res,n,i,m);
        return ans;
    }
};