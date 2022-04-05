class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int h = height.size()-1;
        int low_max =height[0];
        int right_max= height[h-1];
        int final_ans = 0;
        while(l <= h)
        {
            low_max = max(low_max,height[l]);
            right_max = max(right_max,height[h]);
            int minimum = min(height[l],height[h]);
            final_ans = max(final_ans,(h-l) * minimum);
            if(height[l] < height[h])
            {
                l++;
            }
            else if(height[l] > height[h])
            {
                h--;
            }
            else
            {
                l++;
                h--;
            }
        }
        return final_ans;
    }
};