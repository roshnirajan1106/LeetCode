class Solution {
public:
    bool check(int i ,int j,vector<vector<char>>&board ,int n)
    {
        //upside
        for(int k = 0;k<i;k++)
        {
            if(board[k][j] == 'Q')
                return false;
        }
        int l = i;
        int m = j;
        while(l >= 0 && m >= 0)
        {
            if(board[l][m] == 'Q')
                return false;
            
            l--;
            m--;
        }
        l = i;
        m =j;
        
        while(l>= 0 && m<n)
        {
            if(board[l][m] == 'Q')
                return false;
            
            l--;
            m++;
        }
        
        return true;
        
    }
    bool solve(vector<vector<char>>&board,int i,int n,int &ans)
    {
        if( i == n)
        {
            ans ++;
            return false;
        }
        for(int j = 0;j<n;j++)
        {
            if(check(i,j,board,n))
            {
                board[i][j] = 'Q';
                bool res = solve(board,i+1,n,ans);
                if(res == true)
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    int totalNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
        int ans = 0;
        solve(board,0,n,ans);
        return ans;
    }
};