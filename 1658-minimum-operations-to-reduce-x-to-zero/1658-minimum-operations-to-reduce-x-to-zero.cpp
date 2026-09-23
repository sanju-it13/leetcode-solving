class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=0;
        for(int num : nums)
           total+=num;
        int target = total - x;
        if (target==0) return nums.size();
        if(target<0) return -1;
        int Currsum=0;
        int maxLen=-1;
        int left=0;
        for(int right=0;right<nums.size();right++){
            Currsum+=nums[right];
              // shrink window if Currsum > target
             while(Currsum > target && left<=right){
                Currsum-=nums[left];
                left++;
             }
            if(Currsum == target){
                int Currlength=right-left+1;
                maxLen=max(maxLen,Currlength);
            }
        }

        return (maxLen==-1) ? -1 : (nums.size()-maxLen);
        
    }
};