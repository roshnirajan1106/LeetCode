class Solution {
public:
    int find(int i,vector<int>&parent)
    {
        if(parent[i] == -1)
            return i;
        return parent[i] = find(parent[i],parent);
    }
    void unionset(int i , int j , vector<int>&parent,vector<int>&rank)
    {
        int s1 = find(i,parent);
        int s2 = find(j,parent);
        if(s1 == s2)
            return ;
        if(rank[s1] > rank[s2])
        {
             rank[s1] += rank[s2];
            parent[s2] = s1;
            
        }
        else{
           rank[s2] += rank[s1];
            parent[s1] = s2; 
        }
            
        
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<int>parent(n,-1);
        vector<int>rank(n,1);
        for(auto p :pairs)
        {
            int i = p[0];
            int j = p[1];
            if(parent[j] == -1)
            unionset(i,j,parent,rank);
            else
                unionset(j,i,parent,rank);
        }
        for(int i = 0;i<n;i++)
        {
            find(i,parent);
        }
        cout<<endl;
        vector<vector<int>>v(n);
        vector<vector<char>>c(n);
        for(int i = 0;i<n;i++)
        {
            if(parent[i] == -1)
            {
                v[i].push_back(i);
                
            }
                
            else
            {
                v[parent[i]].push_back(i);
            }
                
        }
        vector<char> res(n,'\0');
        for(auto p : v)
        {
            if(p.empty())
                continue;
            string ss ="";
            for(auto q : p)
            {
                ss += s[q];
            }
            
            sort(ss.begin(),ss.end());
            cout<<ss<<endl;
            for(int i = 0;i<p.size();i++)
            {
                res[p[i]] = ss[i];
            }
            
        }
        string str ="";
        for(auto p :res)
            str +=p;
        
        return str;
        
        
        
        
        
        
    }
};