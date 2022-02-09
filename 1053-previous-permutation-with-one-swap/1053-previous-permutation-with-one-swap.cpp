class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n  = arr.size();
        int i = n-2;
        while(i >= 0)
        {
            if(arr[i] > arr[i+1])
                break;
            
            i--;
        }
        if(i == -1)
            return arr;
        
        int idx = n-1;
        while(idx > i)
        {
            if(arr[idx] < arr[i] && arr[idx-1] != arr[idx])
            {
                swap(arr[idx],arr[i]);
                break;
            }
            idx--;
        }
        return arr;
    }
};