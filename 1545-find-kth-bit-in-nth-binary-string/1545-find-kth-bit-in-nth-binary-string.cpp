class Solution {
public:
    int find(int n,int k)
    {
        if(n == 1)
            return 0;
        int len = (1 << n) - 1;
        int mid = len/2;
        if(k == mid  + 1 )
            return 1;
        if(k <= mid)
            return find(n-1,k);
        return !find(n-1,len - k +1);
    }
    char findKthBit(int n, int k) {
        int ans = find(n,k);
            return ans +'0';
    }
};