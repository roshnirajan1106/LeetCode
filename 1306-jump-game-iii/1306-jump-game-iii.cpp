class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        q.push(start);
        int n = arr.size();
        vector<int>vis(n,0);
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            if(arr[top] == 0)
                return true;
            
            int r = top + arr[top];
            int l = top- arr[top];
            if(r <= n-1 && vis[r] == 0)
            {
                q.push(r);
                vis[r] = 1;
            }
            if(l >= 0 && vis[l] == 0)
            {
                q.push(l);
                vis[l] = 1;
            }
        }
        return false;
    }
};