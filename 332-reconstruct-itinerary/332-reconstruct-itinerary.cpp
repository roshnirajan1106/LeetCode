class Solution {
public:
    
    void dfs(string src, vector<string>&output,  map<string,multiset<string>>&graph)
    {
        while(graph[src].size() > 0)
        {
            string x = *graph[src].begin();
            graph[src].erase(graph[src].begin());
            
            dfs(x,output,graph);
        }
        output.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,multiset<string>>graph;
        for(auto p : tickets)
        {
            string src =p[0];
            string dest = p[1];
            graph[src].insert(dest);
        }
        
        string src ="JFK";
        vector<string>output;
        dfs(src, output, graph);
        reverse(output.begin(),output.end());
        return output;
        
    }
};