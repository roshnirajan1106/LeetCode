class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int m = horizontalCuts.size();
        int n = verticalCuts.size();
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int max_hor = max(horizontalCuts[0],h-horizontalCuts[m-1]);
        int max_ver = max(verticalCuts[0],w-verticalCuts[n-1]);
        int mod = 1000000007;
        for(int i = 1;i<m;i++)
        {
            max_hor = max(max_hor,horizontalCuts[i] - horizontalCuts[i-1]);
        }
         for(int i = 1;i<n;i++)
        {
            max_ver = max(max_ver,verticalCuts[i] - verticalCuts[i-1]);
        }
        cout<<max_hor<<" "<<max_ver<<endl;
        return (long)max_hor * max_ver % 1000000007;
    }
};