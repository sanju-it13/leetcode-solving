class Solution {
public:

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();
         
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));  

        for(int index=n-1;index>=0;index--){
    
          // total remaining stone 
           int total =0;
           for(int i=index;i<n;i++){
            total+=piles[i];
           }

        for(int M=1;M<=n;M++){

             int answer=0;

        for(int X=1;X<=2*M;X++){
            
            // from first index to X -> taken by Alice.. So Bob can take from (index+X)
            // index+x can go upto piles.size();
            if(index+X >n) break;

            int newM =max(X,M);

            int Bob = dp[index+X][newM];

            // Alice collected Stone = Total - Bob collected stone
            answer = max (answer, total- Bob);
        }
        dp[index][M]=answer;
        }
        }

       return dp[0][1]; 
    }
};