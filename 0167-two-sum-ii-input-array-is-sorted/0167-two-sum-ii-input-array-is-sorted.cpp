class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       // two pointer
       int i=0,j=nums.size()-1;
       vector<int>a;
       while(i<j){
        int ans=nums[i]+nums[j];
        
        if(ans == target){
            a.push_back(i+1);
            a.push_back(j+1);
           break;
        }

        if(ans > target)
         j--;
        else{
            i++;
        } 
       }
       return a;
        
    }
};