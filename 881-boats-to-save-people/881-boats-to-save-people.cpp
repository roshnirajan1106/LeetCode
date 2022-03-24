class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int s  =0;
        int e = people.size()-1;
        int count= 0;
        while(s <e)
        {
            int totalWeight = people[s] + people[e];
            if(totalWeight <= limit)
            {
                count++;
                s++;
                e--;
            }
            else{
                e--;
                count++;
            }
        }
        if(s == e)
            count++;
        return count;
    }
};