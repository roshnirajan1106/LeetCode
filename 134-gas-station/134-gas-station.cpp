class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        for(int i = 0 ;i<gas.size() ;i++)
        {
            total += gas[i]-cost[i];
        }
        if(total< 0)
            return -1;
        int start = 0;
        int curr =0;
        for(int i = 0 ; i<gas.size();i++)
        {
            curr += gas[i]-cost[i];
            if(curr < 0)
            {
                curr = 0 ;
                start = i+1;
            }
        }
        return start;
    }
};
//n = gas.size()
// 0....i....n
//lets say at position i, we've negative value
// so we keep the start from i+1
// now we go follow the saame rules till end
// now if we've reached the end and it becomes a valid toor from i+1 - end
// from i - i+1, i couldnt go but there exists a solution because we already checked the total 
// also if we know from 0 - i its a valid toour and i - i+1 is not valid and i+1 -end comes valid then
// start from i +1 to i to i+1 because there exists a soln.