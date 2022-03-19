class Solution {
public:
    bool solve(vector<vector<char>>& board, string &word,int i,int j,int m,int n,int p)
    {
        if(p == word.length())
            return true;
        if(i > m-1 || j > n-1 || j<0 || i<0 || board[i][j] == '.')
            return false;
        
        
        if(board[i][j] != word[p])
            return false;
        
        char c=board[i][j];
        board[i][j] = '.';
            
            bool ans = solve(board,word,i+1,j,m,n,p+1) || solve(board,word,i-1,j,m,n,p+1) || solve(board,word,i,j+1,m,n,p+1) ||     solve(board,word,i,j-1,m,n,p+1);
        board[i][j] = c;
            
        return ans;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int p = 0;
        bool ans = false;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(board[i][j] == word[0])
                {
                    ans = ans || solve(board,word,i,j,m,n,p);
                }
            }
        }
        return ans;
    }
};