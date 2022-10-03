class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(neededTime[0]);
        int ans = 0;
        for(int i = 1;i<colors.length();i++)
        {
             while( i<colors.length() && colors[i] == colors[i-1])
             {
                 pq.push(neededTime[i]);
                 i++;
             }
            while(pq.size() > 1)
            {
                ans += pq.top();
                pq.pop();
            }
            
            pq.pop();
            if(i < colors.length())
            pq.push(neededTime[i]);
            
            
        }
        return ans;
    }
};