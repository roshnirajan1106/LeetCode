class Solution {
public:
   void dfs(string src, vector<string>&output, map<string,multiset<string>>&graph)
   {
       while(graph[src].size())
       {   
           string p = *graph[src].begin();
           graph[src].erase(graph[src].begin());
           dfs(p, output, graph);
       }
       output.push_back(src);
   }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
         map<string,multiset<string>> graph;
        for(auto p : tickets)
        {
            string src = p[0];
            string dest = p[1];
            graph[src].insert(dest);
        }
        vector<string>output;
        string src = "JFK";
        
         dfs(src, output, graph);
        reverse(output.begin(), output.end());
        return output;
        
    }
};