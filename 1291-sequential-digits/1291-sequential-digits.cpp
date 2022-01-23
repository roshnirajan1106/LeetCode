class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        //make an array
        vector<int>output ;
        
        vector<long int> store={-1,9,8,7,6,5,4,3,2,1};
        vector<long int> arr={-1,1,12,123,1234,12345,123456,1234567,12345678,123456789};
        vector<long int> arr1={-1,1,11,111,1111,11111,111111,1111111,11111111,111111111};
        //extract number of digit in low and high
        int cnt_low= 0;
        int cnt_high = 0;
        int temp = low;
        while(temp != 0)
        {
            cnt_low++;
            temp = temp/10;
        }
        temp = high;
        while(temp!=0)
        {
            cnt_high ++;
            temp = temp/10;
        }
        cnt_high = min(cnt_high,9);
        for(int k = cnt_low ; k<=cnt_high;k++)
        {   long int temp1 = arr[k];
            long int add = arr1[k];
            for(int j = 0 ;j < store[k] ;j++)
            {
                if(temp1 < low)
                {   temp1 += add;
                    continue;
                }
                    
                if(temp1 > high)
                    break;
                output.push_back(temp1);
                temp1 += add;
            }
        }
        return output;
            
    }
};