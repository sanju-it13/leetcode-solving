class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>count;
        int start=0,end=0,length=0;

        while(end<nums.size()){
            count[nums[end]]++;

            // window shrink (decrease)
            while(count[nums[end]]>k){
                count[nums[start]]--;
                start++;
            }
          length=max(length,end-start+1);
         // window increase
         end++;
        }
        return length;
    }
};