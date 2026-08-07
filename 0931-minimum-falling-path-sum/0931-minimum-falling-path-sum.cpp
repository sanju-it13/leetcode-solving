class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        for(int i=n-2; i>=0;i--){
           for(int j = n-1;j>=0;j--){

            // case 1 (row + 1, col)
            int minchoice = matrix[i+1][j];

            // case 2  (row + 1, col - 1)
            if(j>0)
             minchoice = min(minchoice , matrix[i+1][j-1]);

            // case 3 (row + 1, col + 1)
            if (j < n-1)
              minchoice = min(minchoice , matrix[i+1][j+1]);

            matrix[i][j]+=minchoice;  
           }
        }

        int result = INT_MAX;

        for(int j=0;j<n;j++){
            result = min(result,matrix[0][j]);
        }

        return result;
    }
};