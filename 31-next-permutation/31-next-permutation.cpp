class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        int pos = -1;
        while(i > 0)
        {
            if(nums[i-1] < nums[i])
            {
                pos = i-1;
                break;
            }
            i--;
            
        }
        cout<<pos<<endl;
        if(pos == -1)
        {
            reverse(nums.begin(),nums.end());
            return ;
        }
            
        
        int pos1 =0;
        int m = INT_MAX;
        for(int i = pos;i<n;i++)
        {
            if(nums[pos] < nums[i] && nums[i] < m)
            {
                pos1 = i;
                m = nums[i];
            }
        }
        cout<<pos<<" "<<pos1<<endl;
        swap(nums[pos],nums[pos1]);
        
        sort(nums.begin() + pos + 1,nums.end());
        
    }
};