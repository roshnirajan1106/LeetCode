class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int small = prices[0];
        int large = prices[0];
        for(int i =1 ;i < prices.size();i++)
        {
            if(prices[i] < small)
            {
                small = prices[i];
                large  = prices[i];
            }
            else{
                large = max(large,prices[i]);
            }
            ans = max(ans, large- small);
        }
        return ans;
    }
};