class Solution {
public:
    double bfs(map<string,vector<pair<string,double>>> &graph,string src, string dest,map<string,int>visited)
    {
       queue<pair<string,double>>q;
        q.push({src,1});
        while(!q.empty())
        {
            pair<string,double> top =q.front();
            cout<<top.first<<" --> ";
            q.pop();
            visited[top.first] = 1;
            if(top.first == dest)
                return top.second;
            for(auto p : graph[top.first])
            {
                if(visited[p.first] ==0)
                {   cout<<p.first<<" "<<p.second*top.second<<endl;
                    q.push({p.first, p.second*top.second});
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>output;
        unordered_set<string> words;
        map<string,int> visited;
        map<string,vector<pair<string,double>>> graph;
        int n =equations.size();
        for(int i = 0;i<n;i++)
        {
            string src = equations[i][0];
            string dest =equations[i][1];
            double value = values[i];
            words.insert(src);
            words.insert(dest);
            visited[src] = 0;
            visited[dest]=0;
            graph[src].push_back({dest,value});
            graph[dest].push_back({src, 1/value});
        }
        for(int i = 0;i<queries.size();i++)
        {
            string src  = queries[i][0];
            string dest = queries[i][1];
            if(words.find(src) == words.end() || words.find(dest) == words.end())
            {   double ans = -1;
                output.push_back(ans);
            }
            else{
                double ans = bfs(graph, src,  dest,visited);
                output.push_back(ans);
            }
        }
        return output;
    }
};