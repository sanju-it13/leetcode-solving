class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

       // mini suffix..
        vector<int>minsuffix(n);
        minsuffix[n-1]=nums[n-1];
        for(int i =n-2;i>=0;i--){
            minsuffix[i]=min(minsuffix[i+1],nums[i]);
         }

         int maxi=nums[0];
        for(int i=0; i<n;i++){
         maxi=max(maxi,nums[i]);  

        int stable = maxi - minsuffix[i];
        if(stable <= k)
          return i;
        
        }
       return -1;
    }
};