class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int left_max =INT_MIN;
        int right_max = INT_MIN;
        int ans = INT_MIN;
        int res;
        while(left < right)
        {
            left_max = max(left_max,height[left]);
            right_max = max(right_max,height[right]);
            res = min(right_max,left_max)*(right-left);
            ans = max(ans,res);
            if(left_max<right_max)
                left++;
            else if(left_max>right_max)
                right--;
            else
            {
                left++;
                right--;
            }
        }
        return ans;
    }
};