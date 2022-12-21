class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        int cnt = 0;
        int answer = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] == 0)
            {
                cnt ++;
                while(cnt > k)
                {
                    if(nums[low] == 0)
                        cnt--;
                    low++;
                    
                }
                    
            }
            answer = max(answer,i-low+1);
        }
        return answer;
    }
};