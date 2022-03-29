class Solution {
public:
    void dfs(int i,int j,int m,int n,int newColor, int temp,vector<vector<int>>& image){
        if(i > m-1 || j > n-1 || i < 0 || j < 0)
            return ;
        if(image[i][j] != temp)
            return ;
        
        image[i][j] = newColor;
        
        dfs(i+1,j,m,n,newColor,temp,image);
        dfs(i-1,j,m,n,newColor,temp,image);
        dfs(i,j+1,m,n,newColor,temp,image);
        dfs(i,j-1,m,n,newColor,temp,image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int temp = image[sr][sc];
        if(temp == newColor)
            return image;
        dfs(sr,sc,m,n,newColor,temp,image);
        return image;
    }
    
};