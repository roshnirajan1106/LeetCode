class Solution {
public:
    int trap(vector<int>& height) {
         stack<int>s;
        int n = height.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        for(int i = 0;i<n;i++)
        {
            while(!s.empty() && s.top() < height[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                
                left[i] = 0;
                s.push(height[i]);
            }
                
            else
                left[i] = s.top();
            
        
        }
        stack<int>str;
        for(int i = n-1;i>=0;i--)
        {
            while(!str.empty() && str.top() < height[i])
            {
                str.pop();
            }
            if(str.empty())
            {
                
                right[i] = 0;
                str.push(height[i]);
            }
                
            else
                right[i] = str.top();
            
        
        }
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            int m = min(left[i],right[i]);
            ans += max(0,m - height[i]);
        }
        return ans;
    }
};