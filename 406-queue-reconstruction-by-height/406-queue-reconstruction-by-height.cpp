class Solution {
public:
    static bool comp(vector<int>&p1, vector<int>&p2)
    {
        return p1[1] < p2[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>>res;
        sort(people.begin(),people.end(), comp);
        int n = people.size();
        res.push_back(people[0]);
        for(int i = 1 ;i<n;i++)
        {   int cnt = 0;
            for(int j=0;j<i;j++)
            {
                if(people[j][0] >= people[i][0])
                    cnt++;
            }
         int k= i;
         res.push_back(people[i]);
         while(cnt != people[i][1] && k >0)
         {
             swap(res[k],res[k-1]);
             cnt--;
             k--;
         }
         
        }
        return res;
    }
};