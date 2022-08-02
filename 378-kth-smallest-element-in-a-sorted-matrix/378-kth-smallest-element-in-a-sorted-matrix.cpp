class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> >pq;
        int m = matrix.size();
        for(int i = 0;i<min(m,k);i++)
        {
            pq.push({matrix[i][0],{i,0}});
        }
        int ans = 0;
        for(int i = 0;i<k;i++)
        {
            auto top = pq.top();
            pq.pop();
            ans = top.first;
            int r = top.second.first;
            int c = top.second.second;
            if(c + 1 < m)
            {
                pq.push({matrix[r][c+1],{r,c+1}});
            }
        }
        return ans;
    }
};