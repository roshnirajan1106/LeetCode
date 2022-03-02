class Solution {
public:
    int soln(int n,int k, int s, vector<int>&ans)
    {
        if(n == 1)
            return ans[s];
        
        ans.erase(ans.begin() + s);
        n = n-1;
        s = (s + k) % n;
        return soln(n,k,s,ans);
    }
    int findTheWinner(int n, int k) {
        k--;
        vector<int>ans;
        for(int i = 1;i<=n;i++)
        {
            ans.push_back(i);
        }
        int s = k % n;
        return soln(n,k,s,ans);
    }
};