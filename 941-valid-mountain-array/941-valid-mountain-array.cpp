class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
      if(arr.size() == 1 || arr.size() ==2)
          return false;
        if(arr[0] >= arr[1])
            return false;
        int flag = 0;
        int prev= INT_MIN;
        for(int i = 0 ;i<arr.size();i++)
        {
            if(!flag)
            {
                if(prev < arr[i])
                    prev = arr[i];
                else if(prev > arr[i])
                {
                    prev = arr[i];
                    flag = 1;
                }
                else 
                    return false;
            }
            else{
                if(prev > arr[i])
                    prev = arr[i];
                else
                    return false;
            }
        }
        if(flag == 0)
            return false;
        return true;
    }
};