class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0] = n;
        right[n-1] = n;
        for(int i = 1; i< n ;i++)
        {
            if(seats[i-1] == 1)
                left[i] =1;
            if(seats[i-1] == 0)
                left[i] = left[i-1] + 1;
            
        }
        for(int i = n-2 ;i >=0 ;i--)
        {
            if(seats[i+1] == 1)
                right[i] = 1;
            if(seats[i+1] == 0)
                right[i] = 1 + right[i+1];
        }
        vector<int> res(n,0);
        int ans = -1;
        for(int i = 0; i< n ; i ++)
        {
         res[i] = min(left[i], right[i]);
            if(seats[i] == 0)
                ans = max(ans, res[i]);
        }
        return ans;
    }
};