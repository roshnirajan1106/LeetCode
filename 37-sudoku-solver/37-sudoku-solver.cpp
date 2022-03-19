class Solution {
public:
    bool check(int i,int j, vector<vector<char>>& board,char val)
    {
        int m =board.size();
        int n = board[0].size();
        for(int k = 0;k<m;k++)
        {
            if(board[k][j] == val)
                return false;
        }
        for(int k =0;k<n;k++)
        {
            if(board[i][k] == val)
                return false;
        }
        int xx = (i/3)*3;
        int yy = (j/3)*3;
        cout<<xx<<" "<<yy<<endl;
        for(int k = 0;k<3;k++)
        {
            for(int l = 0;l<3;l++)
            {
                if(board[xx+k][yy+l] == val)
                    return false;
            }
        }
        return true;
            
    }
    bool solve(int i,int j,int m,int n, vector<vector<char>>& board)
    {
        if(j == n)
            return solve(i+1,0,m,n,board);
        if(i == m)
            return true;
        if(board[i][j] != '.')
            return solve(i,j+1,m,n,board);
        
        for(char k ='1' ;k<='9';k++)
        {
            if(check(i,j,board,k))
            {
                board[i][j] = k;
                bool ans= solve(i,j+1,m,n,board);
                if(ans == true)
                    return true;
                board[i][j] ='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int m =board.size();
        int n = board[0].size();
        solve(0,0,m,n,board);
    }
};