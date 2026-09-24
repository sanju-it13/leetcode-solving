class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // brute force
        int count=0;
        if(k<=1) return 0;
        int start=0,end=0;
        int product=1;
        while(end<nums.size()){
          product*=nums[end];
          while(product >=k){
            // shrink the window
            product/=nums[start];
            start++;
          }
          int length=end-start+1;
          count+=length;
          end++;
        }
         
       return count;
    }
};