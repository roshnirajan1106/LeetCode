class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0; 
        for(int i = 0; i<gas.size();i++)
        {
            sum += gas[i] - cost[i];
        }
        if(sum < 0)
            return -1;
        
        int start = 0;
        int diff = 0;
        int n = gas.size();
        for(int i = 0;i< n-1;i++)
        {
            diff += gas[i] - cost[i];
            if(diff < 0)
            {
                start = i +1;
                diff = 0;
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


// if total gas - cost > 0 then obviously theres a solution
