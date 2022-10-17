class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0;
        int hi = height.size()-1;
        int ans =0;
        while(lo < hi)
        {
            int water = (hi - lo)*(min(height[hi],height[lo]));
            ans = max(ans,water);
            if(height[lo] < height[hi])
            {
                lo++;
            }
            else
            {
                hi--;
            }
        }
        return ans;
    }
};