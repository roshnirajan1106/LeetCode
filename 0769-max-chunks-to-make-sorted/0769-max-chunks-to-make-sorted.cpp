class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int prev = -1;
        int cnt = 0 ;
        int i = 0;
        int n = arr.size();
        while(i < n)
        {
            if(i > prev)
            {
                cnt ++;
                
            }
            prev = max(arr[i],prev);
            i++;
        }
        return cnt;
    }
};