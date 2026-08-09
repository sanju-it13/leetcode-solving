class Solution {
public:

    int stoneCollect(int index , int M, vector<int>&piles,vector<vector<int>>&dp){
        int n=piles.size();
       
        if(index>=n) return 0;

        if(dp[index][M]!=-1) return dp[index][M];

         // total remaining stone 
        int total =0;
        for(int i=index;i<n;i++){
            total+=piles[i];
        }

        int answer=0;
        for(int X=1;X<=2*M;X++){
            
            // from first index to X -> taken by Alice.. So Bob can take from (index+X)
            // index+x can go upto piles.size();
            if(index+X > piles.size()) break;

            int newM =max(X,M);

            int Bob = stoneCollect(index+X,newM,piles,dp);

            // Alice collected Stone = Total - Bob collected stone
            answer = max (answer, total- Bob);
        }
          
        return dp[index][M]=answer;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        // X,M changing part.. 2D dp
        vector<vector<int>>dp(n,vector<int>(n+1,-1));  
       
        return stoneCollect(0,1,piles,dp);
        
    }
};