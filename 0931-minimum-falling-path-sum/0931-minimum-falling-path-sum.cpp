class Solution {
public:
  
  int pathsum(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>&dp) {
    int n = matrix.size();
    if (j<0 || j>n-1)
      return INT_MAX;

    if (i==n-1)
      return matrix[i][j];  

    if (dp[i][j] != INT_MAX)
       return dp[i][j];

    // 3 case

    int down = pathsum(i+1,j,matrix,dp);

    int left = pathsum(i+1,j-1,matrix,dp);

    int right = pathsum(i+1,j+1,matrix,dp);


    return dp[i][j]= matrix[i][j]+min({down,left,right});      

  }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int result = INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));

        for(int j=0; j<n;j++){
            result = min(result, pathsum(0,j,matrix,dp)); // we can choose any element of first row.. 
        }

        return result;
    }   
};