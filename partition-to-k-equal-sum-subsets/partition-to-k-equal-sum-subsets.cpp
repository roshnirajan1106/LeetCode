class Solution {
public:
    bool find_k_sums(int s, vector<int> &nums, vector<int>&visited, int k, int currSum,int currNum ,int target)
    {
        if(k == 1)
            return true;
        
        if(currSum == target && currNum > 0)
            return find_k_sums(0,nums, visited,k-1,0, 0,target);
        
        for(int i = s ;i<nums.size();i++)
        {
            if(visited[i] == 0)
            {   
                visited[i] = 1;
                if(find_k_sums(i+1,nums,visited,k,currSum + nums[i] , currNum+1,target))
                    return true;
                visited[i] = 0;
            }
            
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> visited(n,0);
        int s = 0 ;
        int sum = 0;
        for(auto p : nums)
            sum += p;
        
        if(sum % k !=  0)
            return false;
        int target = sum/k;
        int currSum = 0;
        int currNum = 0;
        return find_k_sums(s,nums, visited, k, currSum, currNum, target);
        
    }
    
    
};