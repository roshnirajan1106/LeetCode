// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int safe(vector<int>&ans, int n,int k,int s)
    {
        if(n == 1)
            return ans[s];
        
        ans.erase(ans.begin() + s);
        n = n-1;
        
        s = (s + k ) % n;
        return safe(ans, n, k,s);
    }
    int safePos(int n, int k) {
        // code here
        vector<int>ans;
        for(int i = 1;i<=n;i++)
        {
            ans.push_back(i);
        }
        k--;
        int s = k % n;
        return safe(ans, n, k,s);
    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}  // } Driver Code Ends