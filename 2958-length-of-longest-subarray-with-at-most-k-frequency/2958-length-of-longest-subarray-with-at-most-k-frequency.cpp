class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>frequency;
        int result=0;
        int left=0;
     for(int i=0;i<n;i++){
        frequency[nums[i]] ++;

        while(frequency[nums[i]] > k){
            frequency[nums[left]] --;
            left++;
        }
        result = max(result , i-left+1);

     }
    
        return result;
    }
};