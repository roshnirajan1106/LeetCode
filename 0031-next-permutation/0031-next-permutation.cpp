class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i =0 ;
        int j = nums.size() - 1;
        int k = j-1;
        int idx = -1;
        int flag = 0;
        while( i <= k && i <=j )
        {
            if(nums[j] > nums[k])
            {
                cout<<k<<" "<<j<<endl;
                idx = k;
                flag = j;
                j = j-1;
                i = k+1;
                k = j -1;
                cout<<"New : ";
              //  cout<<i <<" "<<j<<endl;
                continue;
            }
            if(k == i)
            {
                j = j-1;
                k = j;
            }
            
            k--;
           // cout<<i<<"-"<<j<<"-"<<k<<endl;
        }
        if(idx != -1)
        swap(nums[idx],nums[flag]);
    
        sort(nums.begin() + idx + 1, nums.end());
        
    }
};