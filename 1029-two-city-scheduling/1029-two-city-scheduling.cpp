class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2)
    {
        return v1[1]-v1[0] > v2[1] - v2[0];
     }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),cmp);
        int ans = 0;
        
        int i = 0,j = costs.size()-1;
        while(i < j)
        {
            ans += costs[i][0];
            ans += costs[j][1];
            i++;
            j--;
        }
        return ans;
        
        
    }
};