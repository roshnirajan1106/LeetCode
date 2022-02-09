class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        if(n == 1)
            return  0;
        if( n== 2 && nums[1]-nums[0] == k)
            return 1;
        if(n == 2 && nums[1] - nums[0] != k)
            return 0;
        
        int i = 0,j = 1;
        int cnt = 0;
        set<pair<int,int>>s;
        while(j<n)
        {
            int diff = nums[j] - nums[i];
            
            if(diff == k)
            {     
                s.insert({nums[i],nums[j]});
                i++;
                j++;
                
                
            }
            else if(diff > k )
                i++;
            else if(diff <k)
                j++;
            
            if(i == j)
                j++;
                
        }
        return s.size();
    }
};