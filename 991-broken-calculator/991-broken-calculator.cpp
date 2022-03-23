class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count =0;
        while(target > startValue)
        {
            if(target & 1)
            {
                count++;
                target += 1;
            }
            if(target == startValue)
                return count;
            
            target = target/2;
            count++;
        }
        return count + startValue - target;
    }
};