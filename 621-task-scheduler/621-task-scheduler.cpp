class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> m;
        int count = 0;
        for(int i = 0;i<tasks.size();i++)
        {
            m[tasks[i]] ++;
            count = max(count,m[tasks[i]]);
            
        }
        int nums =0;
        for(auto p : m)
        {
            if(p.second == count)
                nums++;
        }
        int pc = count-1;
        int empty = pc * (n - (nums -1));
        if(empty <= 0)
            return tasks.size();
        
        int available = tasks.size() - nums*count;
        
            return tasks.size() + max(0, empty- available);
        
        
    }
};