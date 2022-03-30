class Solution {
public:
    int reverse(int x) {
        
        int rev = 0;
        while(x != 0)
        {
            int rem = x % 10;
            cout<<rem<<endl;
            x = x/10;
            if(rev == INT_MAX/10 && rem > 7 || rev > INT_MAX/10)
            {
                return 0;
            }
            if(rev == INT_MIN/10 && rem < -8 || rev < INT_MIN/10)
            {
                return 0;
            }
            else
                rev = rev*10 + rem;
            
        }
        return rev;
    }
};