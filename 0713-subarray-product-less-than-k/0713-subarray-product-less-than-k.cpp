class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       
        int count=0;
        int start=0,end=0;
        int product=1;
        while(end<nums.size()){
          product*=nums[end];
          while(product >=k && start<=end){
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