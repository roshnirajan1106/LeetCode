class Solution {
public:
    bool canJump(vector<int>& nums) {
        priority_queue<pair<int,int>>pq;
        int n = nums.size();
        vector<int>visited(n,0);
        int i = 0;
        int walk  = 0 ;
        while(true)
        {
            if(i == n-1)
                return true;
            if(visited[i] == 0) 
            {
                pq.push({nums[i],i});
                visited[i] = 1;
            }
                
            if(walk == 0)
            {
                cout<<pq.size()<<endl;
                if(pq.empty())
                    return false;
                auto top = pq.top();
                pq.pop();
                walk = top.first;
                i= top.second;
                continue;
            }
            walk--;
            i++;
            
            
            
            
        }
        return false;
    }
};