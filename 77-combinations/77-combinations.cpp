class Solution {
public:
    void combinations(vector<vector<int>>&ans,vector<int>&res,int i,int n,int k)
    {
        if(k == 0)
        {
           // cout<<endl;
            ans.push_back(res);
            return ;
        }
        if(i == n+1)
            return ;
        for(int j = i;j<=n;j++)
        {
            res.push_back(j);
           // cout<<j<<" ";
            combinations(ans,res,j+1,n,k-1);
            
            res.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>res;
        int i = 1;
        combinations(ans,res,1,n,k);
        return ans;
    }
};