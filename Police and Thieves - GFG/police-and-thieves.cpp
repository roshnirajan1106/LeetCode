// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        //
        set<int>police;
        set<int>theif;
        for(int i = 0;i<n;i++)
        {
            if(arr[i] == 'P')
            police.insert(i);
            else
            theif.insert(i);
        }
        
        int ans = 0;
        while(!police.empty())
        {
            int i = *police.begin();
            police.erase(police.begin());
            while(!theif.empty())
            {
                int j = *theif.begin();
                
                if(j < i && i-j > k)
                {
                    theif.erase(theif.begin());
                    continue;
                }
                
                if(j > i && j - i > k)
                break;
                
                
                ans++;
                theif.erase(theif.begin());
                break;
                
                
                
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 

  // } Driver Code Ends