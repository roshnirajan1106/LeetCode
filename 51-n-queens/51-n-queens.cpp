class Solution {
public:
    bool check(int i ,int j,vector<vector<string>>&board ,int n)
    {
        //upside
        for(int k = 0;k<i;k++)
        {
            if(board[k][j] == "Q")
                return false;
        }
        int l = i;
        int m = j;
        while(l >= 0 && m >= 0)
        {
            if(board[l][m] == "Q")
                return false;
            
            l--;
            m--;
        }
        l = i;
        m =j;
        
        while(l>= 0 && m<n)
        {
            if(board[l][m] == "Q")
                return false;
            
            l--;
            m++;
        }
        
        return true;
        
    }
    void convert(vector<vector<string>>&board, vector<vector<string>>&res)
    {   vector<string>v;
        int n= board.size();
        for(int i = 0;i<board.size();i++)
        {
            string ans ="";
            for(int j = 0;j<n;j++)
            {
                ans +=board[i][j];
            }
            
            v.push_back(ans);
            
        }
        res.push_back(v);
    }
    bool back(int i, vector<vector<string>>&board, int n,vector<vector<string>>&ans)
    {
        if(i == n)
        {
            convert(board,ans);
            return false;
        }
            
        
        for(int j =0;j<n;j++)
        {
            if(check(i,j,board,n))
            {
                board[i][j] ="Q";
                bool ans1= back(i+1,board,n,ans);
                if(ans1 == true)
                    return true;
                
                board[i][j]=".";
            }
            
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n,vector<string>(n,"."));
        vector<vector<string>>res;
        
        back(0,board,n,res);
        
        
        return res;
    }
};