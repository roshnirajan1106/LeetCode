class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
         priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        for(int i = 0;i<points.size();i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int sum = x*x+ y*y;
            pq.push({sum,i});
            
        }
        
        vector<vector<int>> res;
        while(!pq.empty() && k != 0)
        {
            int x = pq.top().second;
            
            res.push_back(points[x]);
            k--;
            pq.pop();
        }
        
        return res;
    }
};