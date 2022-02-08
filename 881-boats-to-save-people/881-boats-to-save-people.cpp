class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int cnt = 0;
        sort(people.begin(),people.end());
        int s= 0;
        int e= people.size()-1;
        while(s <e)
        {
            if(people[e] + people[s ] <= limit)
            {
                cnt ++;
                s++;
                e--;
            }
            if(people[e] + people[s] > limit)
            {
                cnt++;
                e--;
            }
        }
        if(s == e)
            cnt++;
        return cnt;
    }
};