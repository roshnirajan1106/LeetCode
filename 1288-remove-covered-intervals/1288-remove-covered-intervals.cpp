class Solution {
public:
    static bool comp(vector<int>&v1, vector<int>&v2)
    {
        return v1[0] == v2[0] ? v1[1] > v2[1] : v1[0] < v2[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end(),comp);
       int n =intervals.size();
        for(int i = n-2;i>=0;i--)
        {
            for(int j = i+1;j<n;j++)
            {
                if(intervals[j][0] >= intervals[i][0] && intervals[i][1] >= intervals[j][1]) 
                {
                    intervals.erase(intervals.begin() + j);
                    n = intervals.size();
                    cout<<"hello"<<endl;
                    cout<<j<<endl;
                    j = i;
                }
            }
        }
        return intervals.size();
        
    }
};