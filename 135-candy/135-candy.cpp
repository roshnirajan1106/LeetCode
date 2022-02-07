class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        vector<int>chocolates(n,0);
        
        
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0;i<arr.size();i++)
        {
            pq.push({arr[i] , i});
        }
        int ans = 0;
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int idx = top.second;
            int l = idx - 1;
            int r = idx + 1;
            int choco = 0;
            if(l >= 0 && arr[l] < arr[idx])
                choco= chocolates[l];
            if(r <=n-1 && arr[r] < arr[idx])
                choco = max(choco,chocolates[r]);
            
            chocolates[idx] = choco + 1;
            ans += chocolates[idx];
            
        }
        return ans;
    }
};