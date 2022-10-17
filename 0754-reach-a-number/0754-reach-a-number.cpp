class Solution {
public:
    int reachNumber(int target) {
        int step = 0;
        int sum = 0;
        target = abs(target);
        while(true)
        {
            step ++;
            sum += step;
            if(sum == target)
                return step;
            else if(sum > target && ( sum-target) % 2 == 0)
                return step;
        }
        return -1;
    }
};