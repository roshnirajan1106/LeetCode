// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        map<char,vector<char>>graph;
        int i =0;
        int j =1;
        while(j < N)
        {
            if(dict[i][0] != dict[j][0])
            {
                graph[dict[i][0]].push_back(dict[j][0]);
                //cout<<dict[i][0]<<" "<<dict[j][0]<<endl;
            }
            else{
                int len1 = dict[i].length();
                int len2 = dict[j].length();
                int k1 = 0,k2= 0;
                while(k1 < len1 && k2 < len2)
                {
                    //cout<<dict[i][k1]<<" "<<dict[j][k2]<<endl;
                    if(dict[i][k1++] == dict[j][k2++])
                    continue;
                    
                    graph[dict[i][k1-1]].push_back(dict[j][k2-1]);
                    //cout<<dict[i][k1-1]<<"  "<<dict[j][k2-1]<<endl;
                    break;
                    
                }
            }
            i++;
            j++;
        }
        
        // for(auto p : graph)
        // {
        //     cout<<p.first<<"--> ";
        //     for(auto q: p.second)
        //         cout<<q<<" ";
        //     cout<<endl;
        // }
        map<char,int>indegree;
        for(auto p : graph)
        {
            indegree[p.first] = 0;
        }
        for(auto p : graph)
        {
            
            for(auto q : p.second)
                indegree[q]++;
        }
        queue<char>q;
        
        for(auto p : indegree)
        {
            if(p.second == 0)
                q.push(p.first);
        }
        string res="";
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            res += top;
            
            for(auto p : graph[top])
            {
                indegree[p]--;
                if(indegree[p] == 0)
                q.push(p);
            }
        }
       // cout<<res<<endl;
        return res;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends