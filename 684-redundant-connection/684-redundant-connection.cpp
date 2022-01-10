class Solution {
public:
    int find(int x , vector<int> &parent)
    {   
        if(parent[x] == -1)
            return x;
     
        parent[x] = find(parent[x], parent);
        return parent[x];
        // return 1;
    }
    void union_set(int x, int y, vector<int> &parent, vector<int> &rank)
    {  
        int s1 = find(x, parent);
        int s2 = find(y,parent);
        
        if(s1 != s2)
        {
             if(rank[s1] >  rank[s2])
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }else{
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
           
        }
           
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
       vector<int> rank(n,1);
        vector<int> parent(n,-1);
        vector<int> res;
        for(auto p : edges)
        {
            int x= p[0]-1;
            int y = p[1]-1;
            
            int s1 =  find(x,parent);
            int s2 = find(y,parent);
            cout<<s1<<" "<<s2<<endl;
            if(s1 == s2)
            {
                res.push_back(x+1);
                res.push_back(y+1);
                break;
            }
            else{
                union_set(x,y,parent, rank);
                
            }

        
        }
        return res;
    
    }
};