// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void func(vector<string> &ans, string str, int one, int zero, int n)
    {
        if(one > n)
        return ;
        if(one + zero > n)
            return ;
        if(one + zero == n)
        {
           
            ans.push_back(str);
            return ;
        }
        func(ans, str + '1' , one + 1,zero, n);
        
        
        if(  zero < one)
        {
            
            func(ans, str + '0' , one,zero + 1,n);
        }
        
    }
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    vector<string>ans;
	    string str = "";
	    func(ans, str, 0,0, N);
	    return ans;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends