class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int max_left = height[left];
        int max_right= height[right];
        int ans = 0;
        while(left<right)
        {
            max_left= max(max_left,height[left]);
            max_right = max(max_right,height[right]);
            
            int diff = min(max_left,max_right);
            int len = right-left;
            ans = max(ans,diff*len);
            if(height[left] < height[right])
            {
                left++;
                
            }
            else if(height[left] > height[right]){
                right--;
            }
            else{
                left++;
                right--;
            }
        }
        return ans;
    }
};