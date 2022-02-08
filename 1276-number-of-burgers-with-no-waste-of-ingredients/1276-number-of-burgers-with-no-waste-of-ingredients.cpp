class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int c = 2*cheeseSlices;
        int num = tomatoSlices - c;
        vector<int>res;
        if(num <0 || num % 2 != 0)
        {
            return res;
        }
        int j = num / 2;
        int s = cheeseSlices-j;
        if(s  < 0)
            return res;
        res.push_back(j);
        res.push_back(s);
        return res;
    }
};