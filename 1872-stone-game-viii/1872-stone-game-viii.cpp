class Solution {
public:

    int stoneGameVIII(vector<int>& stones) {

        int n = stones.size();
        vector<int>prefixSum(n);
        prefixSum[0]=stones[0];
        for(int i=1; i<n;i++){
            prefixSum[i]=stones[i]+prefixSum[i-1];
        }
        vector<int>dp(n,0);

        dp[n-1]=prefixSum[n-1];
       
        for(int i = n-2;i>=0;i--){

        int stone_pick= prefixSum[i] - dp[i+1];

        int not_pick= dp[i+1];

        dp[i]= max(stone_pick,not_pick);
        } 
        return dp[1];
        
    }
};