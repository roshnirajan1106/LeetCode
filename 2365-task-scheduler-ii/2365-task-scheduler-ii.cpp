class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int,long long>dp;
        long long res = 0;
        for(int i = 0;i<tasks.size();i++)
        {
            if(dp.find(tasks[i]) == dp.end())
            {
                dp[tasks[i]] = ++res;
                //cout<<tasks[i]<<"---->"<<i+1+right<<endl;
            }
            else{
                
                dp[tasks[i]] = max(res,dp[tasks[i]]+space) + 1;
                res = dp[tasks[i]];
                
            }
        }
        int n = tasks.size();
        return dp[tasks[n-1]];
        
    }
};