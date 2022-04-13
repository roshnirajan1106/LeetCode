class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
          vector<vector<int>>arr(n,vector<int>(n,0));
        int num = n*n;
        int flag = 0;
        int cnt = 1;
        int i = 0,j = 0;
        while(cnt <= n*n)
        {
            if(flag == 0)
            {
                while(j < n && arr[i][j] == 0)
                {
                    arr[i][j] = cnt;
                    cnt++;
                    j++;
                }
                j = j -1;
                i = i+1;
               // cout<<i<<" "<<j<<endl;
                 //cout<<cnt<<endl;
                
            }
            else if(flag == 1)
            {
                 //cout<<i<<" "<<j<<endl;
                while(i < n && arr[i][j] == 0)
                {
                    arr[i][j] = cnt;
                    i++;
                    cnt++;
                }
                i = i-1;
                j = j-1;
            }
            else if(flag == 2)
            {
                while(j >= 0 && arr[i][j] == 0)
                {
                    arr[i][j] = cnt;
                    cnt++;
                    j--;
                }
                j = j + 1;
                i = i -1;
                
            }
            else{
                while(i >= 0 && arr[i][j] == 0){
                    arr[i][j] = cnt;
                    cnt++;
                    i--;
                }
                i = i+1;
                j = j +1;
                
            }
            
            flag = (flag + 1) % 4;
            //cout<<"new flag : "<<flag<<endl;
            
        }
        return arr;
    }
};