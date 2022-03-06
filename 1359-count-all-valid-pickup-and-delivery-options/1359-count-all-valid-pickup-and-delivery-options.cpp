class Solution {
public:
    int countOrders(int n) {
        int mod = 1000000007;
        long long res= 1;
        for(int i = 1;i<n+1;i++)
            res  = (res * i) % mod;
        for(int i = 1;i<2*n ;i+= 2)
            res = (res *i) % mod;
        
        
        return res;
    }
};