class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int>s;
        for(auto p : nums1)
            s.insert(p);
        
        int n = nums1.size();
        vector<int>res(n,0);
        for(int i = 0; i<n;i++)
        {
            int num = nums2[i];
            auto it = s.upper_bound(num);
            if(it == s.end())
                continue;
            res[i] = *it;
            s.erase(it);
        }
        
        int i = 0;
        while(!s.empty())
        {
            if(res[i] == 0)
            {
                res[i] = *s.begin();
                s.erase(s.begin());
            }
            i++;
        }
        return res;
        
    }
};