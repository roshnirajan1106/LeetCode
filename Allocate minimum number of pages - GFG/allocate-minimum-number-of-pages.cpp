// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool check(int mid, int m,int A[],int n)
    {
       int sum  = 0;
       int stud = 0;
       
       for(int i = 0;i<n;i++)
       {
           if(A[i] > mid)
           return false;
           if(sum + A[i] > mid)
           {
               stud++;
               sum = A[i];
               if(stud == m)
               return false;
           }
           else
           sum += A[i];
       }
       return true;
    }
    int findPages(int A[], int N, int M) 
    {
        //code heroe
        int small = A[N-1];
        int sum = 0;
        for(int i = 0;i<N;i++)
        sum += A[i];
        
        
        int largest = sum;
        int ans = 0;
        while(small <= largest)
        {
            int mid = small + (largest-small)/2;
          //  cout<<endl;
        // cout<<mid<<endl;
           // cout<<"heyyyyyyyy"<<endl;
            if(check(mid,M,A,N))
            {
               //cout<<"hello";
                ans = mid;
               // cout<<ans<<endl;
                largest = mid-1;
            }
            else
            small = mid+1;
            
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends