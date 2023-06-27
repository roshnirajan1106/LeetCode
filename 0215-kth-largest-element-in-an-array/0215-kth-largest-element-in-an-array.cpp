class Solution {
public:
    int partion ( vector<int> &nums, int lo,int hi){
        int pivot = nums[hi];
        int p = lo;
        for(int i = lo;i< hi;i++)
        {
            if(nums[i] > pivot)
                continue;
            else{
                swap(nums[p],nums[i]);
                p = p + 1;
            }
        }
        swap(nums[p],nums[hi]);
        return p;
        
    }
    int solution(int lo, int hi, vector<int>&nums,int k)
    {
            int p = partion(nums,lo,hi);
            if(p == k )
                return nums[k];
            else if(p > k){
                return solution(lo,p-1,nums,k);
            
            }
            
        return solution(p+1,hi,nums,k);
        
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        int lo = 0;
        int hi = nums.size()-1;
        k = nums.size()-k;
        return solution(lo,hi,nums,k);
    }
};