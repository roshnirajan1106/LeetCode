class Solution {
public:
    void dfs(int s, int sum, vector<int>temp, vector<vector<int>>&res, int n,int k)
    {   if(sum == n && temp.size() == k)
        {
                res.push_back(temp);
            return;
        }
        if(s == 10)
            return;
        if(temp.size() > k)
            return;
        if(sum > n)
            return ;
        
        for(int i = s;i<10;i++)
        {
            temp.push_back(i);
            dfs(i+1,sum + i,temp,res,n,k);
            temp.pop_back();
        }
        
    
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>>res;
        int sum = 0;
        int s = 1;
        dfs(s,sum,temp,res,n,k);
        return res;
    }
};