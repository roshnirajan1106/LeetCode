class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int maxi_idx = 0;
        int n = nums.size()-1;
        int mini_idx = 0; 
        for(int i = 1;i<nums.size();i++){
           if(nums[i] > maxi){
               maxi = nums[i];
               maxi_idx = i;
           }else if(nums[i] < mini){
               mini = nums[i];
               mini_idx= i;
           }
                
        }
        int small =0;
        int big = 0;
        if(mini_idx == maxi_idx){
            int ans = min(mini_idx - 0 , n-mini_idx) + 1;
            return ans;
        }else if(maxi_idx > mini_idx){
            small = mini_idx;
            big = maxi_idx;
        }else{
            small = maxi_idx;
            big = mini_idx;
        }
        cout<<small<<" "<<big<<endl;
        int ans1 = small + min(big-(small+1),n-big) + 2; 
        int ans2 = n - big + min(small, (big-1) - small ) + 2;
        cout<<ans1<<" "<<ans2<<endl;
        return min(ans1,ans2);
        
        
    }
};