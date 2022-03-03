class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int>ans;
        for(int i = 1;i<nums.size();i++)
        {
            ans.push_back(nums[i] - nums[i-1]);
        }
        int n = ans.size();
        vector<int>res;
        int count = 1;
        for(int i = 1; i<n;i++)
        {
            if(ans[i] == ans[i-1])
                count++;
            else{
                res.push_back(count + 1);
                count = 1;
            }
        }
        res.push_back(count + 1);
        int answer = 0;
        for(auto p : res)
        {
            if(p <3)
                continue;
            for(int i = 3;i<=p;i++)
            {
                answer += p - i + 1;
            }
        }
        
        
        return answer;
    }
};