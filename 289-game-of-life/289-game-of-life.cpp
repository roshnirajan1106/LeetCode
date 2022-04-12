class Solution {
public:
    int number(int i ,int j, vector<vector<int>>& board)
    {
        int m = board.size();
        int n = board[0].size();
        int count = 0;
        // i-1,j-1 , i -1 , j , i -1 , j+1
        // i , j -1 , i , j+1
        // i + 1, j -1 , i + 1, j , i +1 ,j+1
        if(i- 1 >= 0 && j - 1 >= 0 && board[i-1][j-1] ==1)
            count++;
         if(i- 1 >= 0  && board[i-1][j] ==1)
            count++;
         if(i- 1 >= 0 && j + 1 < n && board[i-1][j+1] ==1)
            count++;
         if( j - 1 >= 0 && board[i][j-1] ==1)
            count++;
         if( j + 1 < n && board[i][j+1] ==1)
            count++;
         if(i+ 1 < m && j - 1 >= 0 && board[i+1][j-1] ==1)
            count++;
         if(i+ 1 <m && board[i+1][j] ==1)
            count++;
         if(i+1  <m && j + 1 < n && board[i+1][j+1] ==1)
            count++;
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>new_board(m,vector<int>(n,0));

        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(board[i][j] == 0)
                {
                    int num = number(i,j,board);
                    if(num == 3)
                        new_board[i][j] = 1;
                    
                }
                else{
                    int num = number(i,j,board);
                    if(num < 2)
                        new_board[i][j] = 0;
                    else if(num  > 3)
                        new_board[i][j] = 0;
                    else
                        new_board[i][j] = 1;

                }
            }
        }
        board = new_board;
    }
};