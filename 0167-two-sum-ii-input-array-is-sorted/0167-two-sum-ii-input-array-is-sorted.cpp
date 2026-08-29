class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       // two pointer
       int i=0,j=nums.size()-1;
      
       while(i<j){
        int ans=nums[i]+nums[j];
        
        if(ans == target){
           break;
        }

        if(ans > target)
         j--;
        else{
            i++;
        } 
       }
       return {i+1,j+1};
        
    }
};