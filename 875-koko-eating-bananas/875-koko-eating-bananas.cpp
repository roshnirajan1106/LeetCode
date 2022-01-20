class Solution {
public:
    bool is_possible(int mid, int h, vector<int>&piles)
    {   int count=0;
        for(int i = 0 ;i<piles.size();i++)
        {
            if(piles[i] % mid == 0)
            {
                count += piles[i]/mid;
                if(count > h)
                    return false;
            }
            else if(piles[i]% mid >0){
                int x = piles[i]/mid;
                count+= x+1;
                if(count > h)
                    return false;
            }
                
        }
     return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high =100000000;
        for(int i = 0 ; i < piles.size();i++)
        {
            low= min(low, piles[i]);
            high =max(high, piles[i]);
        }
        int  ans = -1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            bool flag = is_possible(mid, h, piles);
            if(flag)
            {
                ans =mid;
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};