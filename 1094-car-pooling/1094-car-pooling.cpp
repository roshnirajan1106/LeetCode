class Solution {
public:
    static bool camp(vector<int>&v1, vector<int>&v2)
    {
        return v1[2] == v2[2] ? v1[1] < v2[1] : v1[2] < v2[2];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(), camp);
        int i =0;
        int n = trips.size();
        while(i < n)
        {
            int s= trips[i][1];
            int e= trips[i][2];
            int c = trips[i][0];
            int temp = capacity - c;
            if(temp < 0)
                return false;
            int j  = i+1;
            for( ;j<n;j++)
            {
                if(trips[j][1] < e)
                    temp = temp - trips[j][0];
                if(temp < 0)
                    return false;
            }
            i++;
        }
        return true;
    }
};