class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // brute force
        int count=0;
         if(k<=1) return 0;
        for(int i=0;i<nums.size();i++){
            long long product=1;
            for(int j=i;j<nums.size();j++){
                product*=nums[j];

                if(product <k)
                  count++;
                else{
                    break;
                }

            }
        }
        return count;
    }
};