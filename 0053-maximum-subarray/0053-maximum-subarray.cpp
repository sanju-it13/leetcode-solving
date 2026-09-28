class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum=INT_MIN;
        int prefixSum=0;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
            maximum=max(prefixSum,maximum);

            if(prefixSum<0)
               prefixSum=0;
        }
        return maximum;
    }
};