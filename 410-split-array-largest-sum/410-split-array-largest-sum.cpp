class Solution {
public:
    bool find(vector<int>&nums,int sum, int m)
    {
        int s = 0;
        int count = 1;
        for(int i = 0;i<nums.size();i++)
        {
            
            if(nums[i] > sum)
                return false;
                
            if(s + nums[i] > sum)
            {
                s = nums[i];
                count++;
                if(count > m)
                    return false;
            }
            else
                s += nums[i];
        }
       
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        int minimum = INT_MAX;
        for(auto p : nums)
        {
            sum += p;
            minimum = min(minimum, p);
        }
        
        int s = 0;
        int e = sum;
        int res;
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            cout<<mid<<" :";
            bool ans = find(nums,mid,m);
            cout<<ans<<endl;
            if(ans == true)
            {
                res = mid;
                e = mid-1;
            }
            else
                s = mid+1;
        }
        
        return res;
    }
};