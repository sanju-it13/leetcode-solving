class Solution {
public:

    bool answer(int n, vector<int>&dp){

        if(n==0) 
         return false; // whoever turn(alice/bob) it was losses game..

        if(dp[n]!=-1)
          return dp[n];

        // alice first turn.. 
        // alice choose any i^2.. (1,4,9,16...).. i^2 <= n..

        // now Bob turn.. 

        //(n - i^2)..  if answer(n-i^2) is true then Bob win.. means alice lose.. but we have to return true only when Alice win..
         //  if answer(n-i^2) is equal to false means Bob lost.. Alice win..

        for(int i=1; i*i <= n; i++ ){
          
           if(answer(n-i*i,dp) == false)
              return dp[n]=true;

        }
        return dp[n]=false;  // alice could never win.
    
    }

    bool winnerSquareGame(int n) {
        vector<int>dp(n+1,-1);
        return answer(n,dp);
    }
};