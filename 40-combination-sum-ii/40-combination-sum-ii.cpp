class Solution {
public:
    void dfs(vector<int>temp, vector<vector<int>> &res, int s, int sum, int target, vector<int>&candidates)
    {
      if(sum == target)
      {
          res.push_back(temp);
          return ;
      }
      if(s == candidates.size())
      {
          return ;
      }
        
       if(sum  > target)
           return ;
        for(int i = s; i<candidates.size();i++)
        {
            if(i > s && (candidates[i-1] == candidates[i])) continue;
            
            temp.push_back(candidates[i]);
            dfs(temp,res, i + 1, sum + candidates[i],target,candidates );
            temp.pop_back();
            
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>>res;
        sort(candidates.begin(), candidates.end());
        dfs(temp,res,0,0,target,candidates);
        
        return res;
        
    }
};