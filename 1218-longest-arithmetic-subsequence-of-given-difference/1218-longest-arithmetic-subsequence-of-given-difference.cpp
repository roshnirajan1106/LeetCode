class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
      map<int, int> m;
        int ans =1;
        m[arr[0]] = 1;
        for(int i =1;i<arr.size();i++)
        {
            int x = arr[i] - difference;
           
            if(m.find(x) != m.end())
            {
                m[arr[i]] = 1 + m[x];
                
                ans = max(ans, m[arr[i]]);
                
            }
            else
                m[arr[i]] =1;
            
        }
        return ans;
        
    }
};