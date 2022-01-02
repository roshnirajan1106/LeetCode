class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n =time.size();
        vector<int> rem( 60,0);
        int ans = 0;
        for(int i = 0 ;i <n;i++)
        {
            int remainder= time[i] % 60;
            rem[remainder] ++;
            if(remainder != 0 && remainder != 30)
            {
                int m = time[i] % 60;
                m = 60 - m;
                ans += rem[m];
                
            }
           
        }
        int m = rem[0];
        int n1 = rem[30];
        ans += (m*(m-1))/2;
        ans+= (n1 * (n1-1)) /2;
        return ans;
    
    }
};