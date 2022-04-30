class Solution {
public:
    double bfs(string src,string dest,map<string,vector<pair<string,double>>>&graph)
    {
        cout<<src<<" "<<dest<<endl;
        double ans = 1.0;
        queue<pair<string,double>>q;
        int n = graph.size();
        map<string,int>visited;
        for(auto p : graph)
            visited[p.first] = 0;
        q.push({src,ans});
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            string c = top.first;
            visited[c] = 1;
            double val =top.second;
            cout<<c<<" "<<val<<endl;
            
            if(c == dest)
                return val;
            for(auto p : graph[c])
            {
                if(visited[p.first] == 0)
                {
                     double res = val*p.second;
                    q.push({p.first,res});
                }
               
                
            }
        }
            return -1;
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>>graph;
        int n = values.size();
        for(int i = 0;i<n;i++)
        {
            string src = equations[i][0];
            string dest = equations[i][1];
            double val = values[i];
            graph[src].push_back({dest,val});
            double x = 1.0/val;
            graph[dest].push_back({src,x});
        }
        vector<double>res;
        for(auto p : queries)
        {
            string src = p[0];
            string dest = p[1];
            if(graph.find(src) == graph.end())
                res.push_back(-1);
            else if(src == dest)
                res.push_back(1);
            else
            {
                double m = bfs(src,dest,graph);
                res.push_back(m);
            }
            
        }
        return res;
    }
};