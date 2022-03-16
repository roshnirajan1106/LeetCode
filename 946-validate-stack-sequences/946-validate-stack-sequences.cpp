class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i =0;
        int j = 0;
        int n = pushed.size();
        stack<int>s;
        while(i<n)
        {
            s.push(pushed[i]);
            i++;
            while(j < n && !s.empty() && popped[j] == s.top())
            {
                j++;
                s.pop();
            }
        }
        while(j < n && !s.empty() && popped[j] == s.top())
            {
                j++;
                s.pop();
            }
        if(j != n)
            return false;
        
        return true;
        
    }
};