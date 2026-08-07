class Solution {
public:
    int findmaxcherry(int row1 , int col1, int row2, int n,vector<vector<int>>& grid, vector<vector<vector<int>>>&dp){


      // we are calculating second person column position using first person row, col and second person row.. because both person take same step to reach any position.. and both person start from same point.. To reduce the DP size .. neglect col2 from findmaxcherry function.. calculate this within the function..
        int col2 = row1 + col1 - row2;


        // base case
        if(row1>=n || row2>=n || col1>=n || col2 >=n )
          return INT_MIN;

        if(grid[row1][col1]==-1 || grid[row2][col2]==-1)
           return INT_MIN;

        if(dp[row1][col1][row2] != -1)
           return dp[row1][col1][row2]; 

        if(row1==n-1 && col1==n-1)
           return grid[n-1][n-1];

        int cherry = grid[row1][col1];

        if(row1 != row2 || col1 != col2)
         cherry+=grid[row2][col2];

        // choice
        // both person go down..
         int DD = findmaxcherry(row1+1, col1, row2+1,n, grid,dp); 

         // one person go Down.. another one Right  
         int DR = findmaxcherry(row1+1, col1, row2,n, grid,dp);

         // one person go right .. another one down
         int RD = findmaxcherry(row1, col1+1, row2+1,n, grid,dp);

         // both right
         int RR = findmaxcherry(row1, col1+1, row2,n, grid,dp);  

         int pick = max({DD,DR,RD,RR});

         if(pick == INT_MIN)
           return dp[row1][col1][row2]= INT_MIN;

       return dp[row1][col1][row2]=cherry+pick;    


    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int answer = findmaxcherry(0,0,0,n,grid,dp);
        
        return max(0,answer);  
    }
};