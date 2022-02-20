class Solution {
public:
    static bool comp(vector<int>&v1, vector<int>&v2)
    {
        return v1[0] == v2[0] ? v1[1] > v2[1] : v1[0] < v2[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end(),comp);
       int n =intervals.size();
        int count = 0;
        int end = intervals[0][1];
        for(int i = 1;i< n;i++ )
        {
            if(intervals[i][1] <= end)
                count ++;
            end=max(end,intervals[i][1]);
        }
        return n - count;
    }
};