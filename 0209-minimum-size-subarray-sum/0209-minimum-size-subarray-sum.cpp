class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0,end=0;
        int total=INT_MAX;
        int sum=0;
        while(end<nums.size()){
            sum+=nums[end];

            while(sum>=target){    // decrease window
                total=min(total,end-start+1);
                sum-=nums[start];
                start++;
            }
            end++;  // window increase
        }
        return total==INT_MAX ? 0 : total;
    }
};