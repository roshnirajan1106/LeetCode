class Solution {
public:
    double bfs(string src, string dest,map<string,vector<pair<string,double>>>&graph,map<string,int>visited){
        queue<pair<string,double>>q;
        q.push({src,1});
        cout<<src<<" "<<dest<<endl;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto top = q.front();
                q.pop();
                
                string s = top.first;
                visited[s] = 1;
                double div = top.second;
                if(s == dest)
                {
                    return div;
                }
                
                for(auto p :graph[s])
                {
                    if(visited[p.first] == 0)
                        q.push({p.first,p.second*div});
                        
                }
            }
        }
        return -1;
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>>graph;
        map<string,int>visited;
        for(int i = 0;i<equations.size();i++)
        {
            string s = equations[i][0];
            string d = equations[i][1];
            graph[s].push_back({d,values[i]});
            graph[d].push_back({s,1/values[i]});
            visited[s] = 0;
            visited[d] = 0;
        }
        vector<double>res;
        for(auto p : queries)
        {
            string s = p[0];
            string d = p[1];
            double ans ;
            if(visited.find(s) == visited.end() || visited.find(d) == visited.end())
            {
                ans = -1;
            }
            
            else if(s == d)
                ans = 1;
            else
                ans = bfs(s,d,graph,visited);
            
            res.push_back(ans);
                
        }
        return res;
        
    }
};