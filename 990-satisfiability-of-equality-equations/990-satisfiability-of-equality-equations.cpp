class Solution {
public:
    char find(int i, vector<int> &parents)
    {
        if(parents[i] == -1)
            return i;
        return parents[i] = find(parents[i],parents);
    }
    void unions(int x, int y, vector<int> &parents)
    {
        int s1 =find(x, parents);
        int s2 = find(y, parents);
        if(s1 != s2)
        {
            parents[s2] = s1;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> parents(26,-1);
        for(auto p: equations)
        {   int x = p[0]-97;
            int y = p[3]-97;
            if(p[1] == '=')
            {
                
                unions(x,y,parents);
            }
           
        }
        for(auto p: equations)
        {   int x = p[0]-97;
            int y = p[3]-97;
            if(p[1] == '!')
            {
                
              int s1 = find(x,parents);
                int s2= find(y,parents);
                if(s1 == s2)
                    return false;
            }
           
        }
        
        return true;
    }
};