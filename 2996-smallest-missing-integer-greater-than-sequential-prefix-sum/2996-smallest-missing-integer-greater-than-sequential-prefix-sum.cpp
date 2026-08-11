class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum=nums[0];

        // O(N)
        for(int j=1;j<n;j++){
            
            if(nums[j]==nums[j-1]+1){
               sum+=nums[j];
            }
            else {
                break;
            }
        }

        // O(NxN)
        for(int i=0;i<n;i++){
            if(sum == nums[i]){
                sum+=1;
                i=-1;
            }
        }
        return sum;

    }
    // TC -> O(N^2)
};