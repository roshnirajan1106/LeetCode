class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int>num1(n);
        vector<int>num2(n);
        num1[0] = cardPoints[0];
        num2[n-1] = cardPoints[n-1];
        for(int i = 1;i<n;i++)
        {
            num1[i] = cardPoints[i] +  num1[i-1];
        }
        for(int i = n-2;i>=0;i--)
        {
            num2[i] = cardPoints[i] +  num2[i+1];
        }
        int ans = max(num1[k-1],num2[n-k]);
        for(int i = 0;i<k-1;i++)
        {
            int ans1 = num1[i];
            int ans2 = num2[n-(k-i)+ 1];
            ans = max(ans, ans1 + ans2);
        }
        return ans;
        
    }
};