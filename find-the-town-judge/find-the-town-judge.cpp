class Solution { 
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> people(n+1,0);
        for(int i = 0 ;i < trust.size() ; i++)
        {
            int x= trust[i][0];
            int y =trust[i][1];
            people[y] ++;
            people[x] --;
        }
       
        int check = 0;
        int ans = 0;
        for(int i = 1; i<=n;i++)
        {
            if(people[i] ==  n-1)
            {
                check = 1;
                ans = i;
            }
        }
        if(check == 0)
            return -1;
        return ans;
    }
};