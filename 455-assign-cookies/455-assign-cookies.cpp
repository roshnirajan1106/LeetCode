class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int>greed;
        priority_queue<int>cookies;
        for(auto p : g)
            greed.push(p);
        for(auto p : s)
            cookies.push(p);
        
        int cnt = 0;
        while(!greed.empty() && !cookies.empty())
        {
            int gr = greed.top();
            int c = cookies.top();
            if(c >= gr)
            {
                cnt++;
                cookies.pop();
                greed.pop();
                
            }
            else if(gr > c)
            {
                greed.pop();
            }
        }
        return cnt;
        
    }
};