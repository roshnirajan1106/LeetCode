class Solution {
public:
    bool dfs(vector<vector<char>>&board,string word,int pos,int i, int j,int m,int n)
    {
        if(pos == word.length())
            return true;
        if(i > m-1 || j >n-1|| i <0 ||j < 0 || board[i][j] == ' ')
            return false;
        if(word[pos] != board[i][j])
            return false;
            char ch = board[i][j];
            board[i][j] = ' ';
            bool ans1 = dfs(board,word,pos+1,i+1,j,m,n);
            bool ans2 = dfs(board,word,pos+1,i-1,j,m,n);
            bool ans3 = dfs(board,word,pos+1,i,j+1,m,n);
            bool ans4 = dfs(board, word,pos+1,i,j-1,m,n);
        
            board[i][j] = ch;
            return ans1 || ans2 || ans3 || ans4;
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(board[i][j] == word[0])
                {
                    bool ans = dfs(board,word,0,i,j,m,n);
                    if(ans == true)
                        return true;
                }
                    
                
            }
        }
        return false;
    }
};