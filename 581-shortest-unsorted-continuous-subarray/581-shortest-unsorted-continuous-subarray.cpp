class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int s = 1;
        int n = nums.size();
        if(n == 0 || n == 1)
            return 0;
        int e = nums.size()-2;
        int smallest = INT_MAX;
        int largest = INT_MIN;
        //int n = nums.size();
        while(s < n)
        {
           if(nums[s-1] <= nums[s] )
               s ++;
            else
                break;
        }
        s = s-1;
        while(e >= 0)
        {
            if(nums[e] <= nums[e+1])
                e--;
            else
                break;
        }
        e = e+1;
        if(s > e)
            return 0;
        for(int i = s;i<=e;i++)
        {
            smallest = min(smallest,nums[i]);
            largest = max(largest,nums[i]);
        }
        
        while(s >=1)
        {
            if(nums[s-1] > smallest)
                s--;
            else 
                break;
        }
        while(e <= nums.size()-2)
        {
            if(nums[e+1] < largest )
                e++;
            else
                break;
        }
        
        return e- s+1;
        
    }
};