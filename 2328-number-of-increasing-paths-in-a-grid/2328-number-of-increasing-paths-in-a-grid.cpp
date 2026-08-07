class Solution {
public:
    int StrictlyIncreasingPath(int r1, int c1 , int row, int col, vector<vector<int>>&grid, vector<vector<int>>&dp){

      long long result=1;

      if(dp[r1][c1]!=-1) return dp[r1][c1];

      // UP
       if(r1-1 >=0 && grid[r1-1][c1]>grid[r1][c1] )
          result+=StrictlyIncreasingPath(r1-1,c1,row,col,grid,dp);
      
      // DOWN 
       
       if(r1+1 < row && grid[r1+1][c1] > grid[r1][c1])
           result+=StrictlyIncreasingPath(r1+1,c1,row,col,grid,dp);

      // LEFT
        if(c1-1 >=0 && grid[r1][c1-1] > grid[r1][c1])
           result+=StrictlyIncreasingPath(r1,c1-1,row,col,grid,dp);

      // RIGHT
         if(c1+1 < col && grid[r1][c1+1] > grid[r1][c1])
           result+=StrictlyIncreasingPath(r1,c1+1,row,col,grid,dp);


        return dp[r1][c1]=result % 1000000007;   

    }

    int countPaths(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        long long totalpath=0;
        vector<vector<int>>dp(row,vector<int>(col,-1));

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                totalpath+=StrictlyIncreasingPath(i,j,row,col,grid,dp);
            }
        }
         totalpath = totalpath % 1000000007 ;
        return totalpath ;
    }
};