class Solution {
public:
   void dfs(string src, vector<string> &output, map<string,vector<string>>&emails, map<string,int> &visited)
   {
       output.push_back(src);
       visited[src] = 1;
       for(auto p : emails[src])
       {
           if(visited[p] == 0)
               dfs(p,output, emails, visited);
       }
   }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       map<string,vector<string>> emails;
       map<string, string> names;
        map<string,int> visited;
        for(int i = 0; i<accounts.size();i++)
        {
            for(int j = 1; j< accounts[i].size();j++)
            {   visited[accounts[i][j]] = 0;
                names[accounts[i][j]] = accounts[i][0];
                for(int k = j+1;k<accounts[i].size();k++)
                {
                    emails[accounts[i][j]].push_back(accounts[i][k]);
                    emails[accounts[i][k]].push_back(accounts[i][j]);
                    
                }
            }
        }
        
        
        vector<string>output;
        vector<vector<string>>ans;
        for(auto p :visited)
        {   if(p.second == 0)
            {
                output.push_back(names[p.first]);
                vector<string>pq;
                dfs(p.first, pq, emails,visited);
                sort(pq.begin(),pq.end());
                
                for(auto p : pq)
                    output.push_back(p);
            ans.push_back(output);
                output.clear();
            }
            
            
        }
       
       return ans;
    }
};