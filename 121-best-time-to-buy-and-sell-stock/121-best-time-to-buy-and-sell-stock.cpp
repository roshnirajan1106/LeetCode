class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i =n-1;
        int profit =INT_MIN;
        int maximum = prices[i];
        while(i>=0)
        {   
            int ans  = maximum - prices[i];
            profit= max(profit,ans);
            maximum = max(maximum , prices[i]);
            i--;
        }
        return profit;
    }
};