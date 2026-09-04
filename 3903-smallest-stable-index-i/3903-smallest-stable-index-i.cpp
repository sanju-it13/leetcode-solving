class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i=0; i<n;i++){
         int maxi= INT_MIN;
         for(int j=0;j<=i;j++){
            maxi=max(maxi,nums[j]);
         }
          int mini = INT_MAX;
          for(int j=i;j<n;j++){
            mini=min(mini,nums[j]);
          }
        
        int stable = maxi - mini;
        if(stable <= k)
          return i;
        
        }
       return -1;
    }
};