class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        vector<int>chocolates(n,1);
        
        for(int i = 1;i<n;i++)
        {
            if(arr[i-1] < arr[i])
                chocolates[i] = chocolates[i-1] + 1;
            
        }
        int ans = 0;
        for(int i = n-2;i>=0;i--)
        {
            if(arr[i] > arr[i+1])
            {
                chocolates[i] = max(chocolates[i], chocolates[i+1] + 1);
            }
        }
        for(auto p : chocolates)
            ans +=p;
        
        return ans;
        
    }
};