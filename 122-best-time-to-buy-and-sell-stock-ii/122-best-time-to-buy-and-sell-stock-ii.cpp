class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>buy(n,0);
        vector<int>sell(n,0);
        buy[0] = -1*prices[0];
        sell[0] = 0;
        for(int i = 1;i<n;i++)
        {
            buy[i] = max(buy[i-1],sell[i-1] -prices[i]);
            sell[i] = max(sell[i-1], prices[i] + buy[i-1] );
            
        }
        return sell[n-1];
    }
};