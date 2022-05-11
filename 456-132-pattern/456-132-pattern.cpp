class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>s;
        int s3 = INT_MIN;
        int n = nums.size()-1;
        s.push(nums[n]);
        for(int i = n-1;i>=0;i--)
        {
            if(nums[i] < s3)
                return true;
            while(!s.empty() && s.top()<nums[i])
            {
                s3 = s.top();
                s.pop();
            }
            s.push(nums[i]);
            
        }
        return false;
    }
};